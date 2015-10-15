/*
400. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.
Have you met this question in a real interview?
Example
Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.
Note
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Challenge Sort is easy but will cost O(nlogn) time. Try to solve it in linear time and space
*/

// The straight-forward solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        int i;
        for (i = 1; i < n; ++i) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};
