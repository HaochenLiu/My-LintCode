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
Space: O(n)
*/

// DP with rolling window.
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // Even number case.
        if (values.size() % 2 == 0) {
            if (firstWinEvenCoins(values)) {
                return true;
            }
        }

        // Count total.
        int sum = 0;
        for (int i = 0; i < values.size(); ++i) {
            sum += values[i];
        }

        // dp[i][n] = max(values[i] + min(dp[i + 2][n - 2], dp[i + 1][n - 2]),
        //               values[i + n - 1] + min(P[i + 1][n - 2], dp[i][n - 2]))
        vector<vector<int>> dp(values.size(), vector<int>(3, 0));

        for (int n = 0; n <= values.size(); ++n) {
            for (int i = 0; i + n - 1 < values.size(); ++i) {
                int a = i + 2 <= values.size() - 1 && n - 2 >= 0 ? dp[i + 2][(n - 2) % 3] : 0;
                int b = i + 1 <= values.size() - 1 && n - 2 >= 0 ? dp[i + 1][(n - 2) % 3] : 0;
                int c = n - 2 >= 0 ? dp[i][(n - 2) % 3] : 0;
                dp[i][n % 3] = max(values[i] + min(a, b),
                                  values[i + n - 1] + min(b, c));
            }
        }
        return dp[0][values.size() % 3] > sum - dp[0][values.size() % 3];
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

        return odd_sum != even_sum;
    }
};
