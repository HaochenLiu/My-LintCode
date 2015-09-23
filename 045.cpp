/*
045. Maximum Subarray Difference

Given an array with integers.
Find two non-overlapping subarrays A and B, which |SUM(A) - SUM(B)| is the largest.
Return the largest difference.
Have you met this question in a real interview?
Example
For [1, 2, -3, 1], return 6
Note
The subarray should contain at least one number
Challenge
O(n) time and O(n) space.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer indicate the value of maximum difference between two
     *          Subarrays
     */
    int maxDiffSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> minl, minr, maxl, maxr;
        int sum;
        int i;
        
        minl.resize(n);
        minr.resize(n);
        maxl.resize(n);
        maxr.resize(n);
        
        minl[0] = nums[0];
        sum = nums[0];
        for (i = 1; i <= n - 1; ++i) {
            sum = min(sum + nums[i], nums[i]);
            minl[i] = min(minl[i - 1], sum);
        }
        
        maxl[0] = nums[0];
        sum = nums[0];
        for (i = 1; i <= n - 1; ++i) {
            sum = max(sum + nums[i], nums[i]);
            maxl[i] = max(maxl[i - 1], sum);
        }
        
        minr[n - 1] = nums[n - 1];
        sum = nums[n - 1];
        for (i = n - 2; i >= 0; --i) {
            sum = min(sum + nums[i], nums[i]);
            minr[i] = min(minr[i + 1], sum);
        }
        
        maxr[n - 1] = nums[n - 1];
        sum = nums[n - 1];
        for (i = n - 2; i >= 0; --i) {
            sum = max(sum + nums[i], nums[i]);
            maxr[i] = max(maxr[i + 1], sum);
        }
        
        int ans = INT_MIN;
        for (i = 0; i < n - 1; ++i) {
            ans = max(ans, abs(maxl[i] - minr[i + 1]));
            ans = max(ans, abs(maxr[i + 1] - minl[i]));
        }
        return ans;
    }
};
