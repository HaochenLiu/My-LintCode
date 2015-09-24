/*
138. Subarray Sum

Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.
Have you met this question in a real interview?
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
Note
There is at least one subarray that it's sum equals to zero.
*/

#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> ans;
        unordered_map<int, int> um;
        int n = nums.size();
        int i;
        int sum = 0;
        for(i = 0; i < n; i++) {
            sum += nums[i];
            if(sum == 0) {
                ans.push_back(0);
                ans.push_back(i);
                return ans;
            }
            if(um.find(sum) != um.end()) {
                ans.push_back(um[sum] + 1);
                ans.push_back(i);
                return ans;
            }
            um[sum] = i;
        }
        return ans;
    }
};
