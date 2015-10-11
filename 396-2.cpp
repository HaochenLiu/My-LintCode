/*
396. Coins in a Line III

There are n coins in a line. Two players take turns to take a coin from one of the ends of the line until there are no more coins left. The player with the larger amount of money wins.
Could you please decide the first player will win or lose?
Have you met this question in a real interview?
Example
Given array A = [3,2,2], return true.
Given array A = [1,2,4], return true.
Given array A = [1,20,4], return false.
Challenge
Follow Up Question:
If n is even. Is there any hacky algorithm that can decide whether first player will win or lose in O(1) memory and O(n) time?
*/

/*
Time:  O(n^2)
Space: O(n^2)
*/

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // Even number case.
        int n = values.size();
        if(n == 1) return true;
        if((n % 2 == 0) && (firstWinEvenCoins(values))) return true;

        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + values[i];
            dp[i][i] = values[i];
            if(i < n) {
                dp[i][i + 1] = max(values[i], values[i + 1]);
            }
        }

        for (int i = 2; i < n; i++) {
            for (int j = 0; i + j < n; j++) {
                int a = sum[i + j + 1] - sum[j];
                dp[j][i + j] = a - min(dp[j + 1][i + j], dp[j][i + j - 1]);
            }
        }
        return (dp[0][n - 1] * 2 > sum[n]);
    }

    // Time: O(n), Space: O(1)
    // Odd / even numbered strategy for even numbered coins
    bool firstWinEvenCoins(const vector<int>& values) {
        int sum = 0;
        int odd_sum = 0;
        int even_sum = 0;
        for (int i = 0; i < values.size(); ++i) {
            sum += values[i];
            if (i % 2 == 0) {
                odd_sum += values[i];
            } else {
                even_sum += values[i];
            }
        }

        return (odd_sum != even_sum);
    }
};
