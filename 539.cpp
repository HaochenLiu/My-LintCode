/*
539. Move Zeroes

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Notice

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
Have you met this question in a real interview? Yes
Example
Given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int len  = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                nums[len] = nums[i];
                len++;
            }
        }
        
        for(int i = len; i < n; i++) {
            nums[i] = 0;
        }

        return;
    }
};
