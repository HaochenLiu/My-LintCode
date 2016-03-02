/*
508. Wiggle Sort

Given an unsorted array nums, reorder it in-place such that

nums[0] <= nums[1] >= nums[2] <= nums[3]....
Have you met this question in a real interview? Yes
 Notice

Please complete the problem in-place.

Example
Tags
Related Problems
 Notes
Given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].
*/

class Solution {
public:
    /**
     * @param nums a list of integer
     * @return void
     */  
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() < 2) return;
        for(int i = 1; i < n; i++) {
            if(i % 2 == 1) {
                if(nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            } else {
                if(nums[i] > nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
};
