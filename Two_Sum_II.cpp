/*
Two Sum II

Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.

Have you met this question in a real interview? Yes
Example
numbers=[2, 7, 11, 15], target=24

return 1

Challenge
Either of the following solutions are acceptable:

O(1) Space, O(nlogn) Time
*/

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        if(nums.size() < 2) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            if(nums[i] + nums[j] > target) {
                res += (j - i);
                j--;
            } else {
                i++;
            }
        }

        return res;
    }
};
