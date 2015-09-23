/*
091. Minimum Adjustment Cost

Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|
Have you met this question in a real interview?
Example
Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal.
Return 2.
Note
You can assume each number in the array is a positive integer and not greater than 100.
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        const int MAXV = 100;
        int n = A.size();
        if (n <= 1) return 0;
        vector<vector<int> > dp;
        dp.resize(n, vector<int>(MAXV + 1, INT_MAX));
        
        int i, j, k;
        for (i = 1; i <= MAXV; ++i) {
            dp[0][i] = abs(i - A[0]);
        }
        int ll, rr;
        for (i = 1; i < n; i++) {
            for (j = 1; j <= MAXV; j++) {
                ll = max(1, j - target);
                rr = min(MAXV, j + target);
                for (k = ll; k <= rr; k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k]);
                }
                dp[i][j] += abs(j - A[i]);
            }
        }
        int ans = INT_MAX;
        for (i = 1; i <= MAXV; i++) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};
