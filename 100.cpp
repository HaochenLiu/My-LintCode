/*
100. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
Have you met this question in a real interview?
Example
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n < 2) return n;
        int len = 0;
        for(int i = 1; i < n; i++) {
            if(nums[len] != nums[i]) {
                len++;
                nums[len] = nums[i];
            }
        }
        
        return len + 1;
    }
};
