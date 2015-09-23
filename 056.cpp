/*
056. 2 Sum

Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.
Have you met this question in a real interview?
Example
numbers=[2, 7, 11, 15], target=9
return [1, 2]
Note
You may assume that each input would have exactly one solution
Challenge
Either of the following solutions are acceptable:
O(n) Space, O(nlogn) Time
O(n) Space, O(n) Time
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        // write your code here
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(m.find(target - nums[i]) != m.end()) {
                return vector<int>{m[target - nums[i]], i + 1};
            } else {
                m[nums[i]] = i + 1;
            }
        }
    }
};
