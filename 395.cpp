/*
395. Coins in a Line II

There are n coins with different value in a line. Two players take turns to take one or two coins from left side until there are no more coins left. The player who take the coins with the most value wins.
Could you please decide the first player will win or lose?
Have you met this question in a real interview?
Example
Given values array A = [1,2,2], return true.
Given A = [1,2,4], return false.
*/

/*
Time: O(n^2)
Space: O(n^2)
Extra Space: O(n^2)
*/

// Solution using DP
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n <= 2) {
            return true;
        }
        
        vector<vector<int> > dp;
        dp.resize(n, vector<int>(n, 0));
        vector<int> sum;
        sum.resize(n + 1, 0);
        
        int i, j;
        for (i = 0; i < n; ++i) {
            dp[i][i] = values[i];
            sum[i + 1] = sum[i] + values[i];
        }
        for (i = 0; i < n - 1; ++i) {
            dp[i][i + 1] = values[i] + values[i + 1];
        }
        for (i = 2; i < n; ++i) {
            for (j = 0; j + i < n; ++j) {
                // Think about why?
                dp[j][j + i] = max(dp[j][j + i], sum[j + i + 1] - sum[j] - dp[j + 1][j + i]);
                dp[j][j + i] = max(dp[j][j + i], sum[j + i + 1] - sum[j] - dp[j + 2][j + i]);
            }
        }
        return dp[0][n - 1] > sum[n] - dp[0][n - 1];
    }
};
