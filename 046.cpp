/*
046. Majority Number

Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.
Have you met this question in a real interview?
Example
Given [1, 1, 1, 1, 2, 2, 2], return 1
Challenge
O(n) time and O(1) extra space
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int vote = 1;
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(vote == 0) {
                cur = nums[i];
                vote++;
            } else if(cur == nums[i]) {
                vote++;
            } else {
                vote--;
            }
        }

        return cur;
    }
};
