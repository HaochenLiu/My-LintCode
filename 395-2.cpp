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
        if (n <= 2) return true;

        vector<int> dp(n, 0);
        int sum = 0;
        int i, j;
        dp[n - 1] = values[n - 1];
        dp[n - 2] = values[n - 2] + values[n - 1];
        sum = values[n - 2] + values[n - 1];

        for (i = n - 3; i >= 0; i--) {
            sum += values[i];
            dp[i] = sum - min(dp[i + 1], dp[i + 2]);
        }

        return (dp[0] * 2 > sum);
    }
};
