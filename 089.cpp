/*
089. k Sum

Given n distinct positive integers, integer k (k <= n) and a number target.
Find k numbers where sum is target. Calculate how many solutions there are?
Have you met this question in a real interview?
Example
Given [1,2,3,4], k = 2, target = 5.
There are 2 solutions: [1,4] and [2,3].
Return 2.
*/

class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return an integer
     */
    int kSum(vector<int> A, int k, int target) {
        vector<int> &a = A;
        sort(a.begin(), a.end());
        while (!a.empty() && a.back() > target) {
            a.pop_back();
        }
        
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        int i;
        int sum = 0;
        for (i = 0; i < n; ++i) {
            sum += a[i];
        }
        if (sum < target) {
            return 0;
        }
        
        int j;
        vector<vector<unordered_map<int, int> > > dp(2);
        dp[0].resize(n);
        dp[1].resize(n);
        
        for (i = 0; i < n; ++i) {
            dp[0][i][0] = 1;
        }
        int f = 1;
        int nf = !f;
        auto it = dp[0][0].begin();
        sum = 0;
        for (i = 1; i <= k; ++i) {
            for (j = 0; j < n; ++j) {
                dp[f][j].clear();
            }
            sum += a[i - 1];
            if (sum <= target) {
                ++dp[f][i - 1][sum];
            }
            for (j = i; j < n; ++j) {
                dp[f][j] = dp[f][j - 1];
                for (it = dp[nf][j - 1].begin(); it != dp[nf][j - 1].end(); ++it) {
                    if (it->first + a[j] > target) {
                        continue;
                    }
                    dp[f][j][it->first + a[j]] += it->second;
                }
            }
            f = !f;
            nf = !f;
        }
        
        return dp[nf][n - 1][target];
    }
};
