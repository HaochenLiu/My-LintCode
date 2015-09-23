/*
042. Maximum Subarray II

Given an array of integers, find two non-overlapping subarrays which have the largest sum.
The number in each subarray should be contiguous.
Return the largest sum.
Have you met this question in a real interview?
Example
For given [1, 3, -1, 2, -1, 2], the two subarrays are [1, 3] and [2, -1, 2] or [1, 3, -1, 2] and [2], they both have the largest sum 7.
Note
The subarray should contain at least one number
Challenge
Can you do it in time complexity O(n) ?
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        int n = nums.size();
        vector<int> dl;
        vector<int> dr;
        dl.resize(n);
        dr.resize(n);
        
        int sum;

        dl[0] = nums[0];
        sum = nums[0];
        for(int i = 1; i <= n - 1; i++) {
            sum = max(sum, 0);
            sum += nums[i];
            dl[i] = max(dl[i - 1], sum);
        }
        
        dr[n - 1] = nums[n - 1];
        sum = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            sum = max(sum, 0);
            sum += nums[i];
            dr[i] = max(dr[i + 1], sum);
        }
        
        sum = dl[0] + dr[1];
        for(int i = 1; i < n - 1; i++) {
            sum = max(sum, dl[i] + dr[i + 1]);
        }
        return sum;
    }
};
