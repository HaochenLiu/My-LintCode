/*
196. Find the Missing Number

Given an array contains N numbers of 0 .. N, find which number doesn't exist in the array.
Have you met this question in a real interview?
Example
Given N = 3 and the array [0, 1, 3], return 2.
Challenge
Do it in-place with O(1) extra memory and O(n) time.
*/

class Solution {
public:
    /**    
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 1;
        
        int pos = 0;
        while(pos < n) {   
            if(nums[pos] >= 1 && nums[pos] <= n && nums[pos] != pos + 1 && nums[pos] != nums[nums[pos] - 1]) {
                swap(nums[pos], nums[nums[pos] - 1]);
            } else {
                pos++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(i + 1 != nums[i]) {
                return i + 1;
            }
        }
        return 0;
    }
};
