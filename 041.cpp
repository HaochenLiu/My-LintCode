/*
041. Maximum Subarray

Given an array of integers, find a contiguous subarray which has the largest sum.
Have you met this question in a real interview?
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.
Note
The subarray should contain at least one number.
Challenge
Can you do it in time complexity O(n)?
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int res = nums[0];
        int sum = nums[0];
        for(int i = 1; i < n; i++) {
            sum = max(sum + nums[i], nums[i]);
            res = max(res, sum);
        }
        
        return res;
    }
};
