/*
044. Minimum Subarray

Given an array of integers, find the subarray with smallest sum.
Return the sum of the subarray.
Have you met this question in a real interview?
Example
For [1, -1, -2, 1], return -3
Note
The subarray should contain at least one integer.
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int res = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            sum = min(sum + nums[i], nums[i]);
            res = min(res, sum);
        }
        
        return res;
    }
};
