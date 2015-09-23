/*
043. Maximum Subarray III

Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.
Have you met this question in a real interview?
Example
Given [-1,4,-2,3,-2,3], k=2, return 8
Note
The subarray should contain at least one number
*/

// O(k * n) DP with O(n) space
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        int n = nums.size();
        if (k <= 0 || k > n) return 0;
        vector<vector<int>> dp(2, vector<int>(n, 0));
        vector<int> mx(n, 0);
        int i, j;
        int f, nf;
        
        mx[0] = nums[0];
        dp[0][0] = nums[0];
        for (i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1] + nums[i], nums[i]);
        }
        mx[0] = dp[0][0];
        for (i = 1; i < n; ++i) {
            mx[i] = max(mx[i - 1], dp[0][i]);
        }
        
        f = 1;
        nf = 0;
        for (i = 1; i < k; i++) {
            dp[f][i] = dp[nf][i - 1] + nums[i];
            for (j = i + 1; j < n; j++) {
                dp[f][j] = max(dp[f][j - 1] + nums[j], mx[j - 1] + nums[j]);
            }
            mx[i] = dp[f][i];
            for (j = i + 1; j < n; j++) {
                mx[j] = max(mx[j - 1], dp[f][j]);
            }
            nf = f;
            f = !f;
        }
        return mx[n - 1];
    }
};
