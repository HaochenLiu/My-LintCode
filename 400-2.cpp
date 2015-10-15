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

// O(n) solution
#include <climits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxVal = nums[0];
        int minVal = nums[0];
        for (int i = 0; i < n; i++) {
            maxVal = max(maxVal, nums[i]);
            minVal = min(minVal, nums[i]);
        }

        int len = (maxVal - minVal - 1) / (n - 1) + 1;
        int cnt = (maxVal - minVal) / len + 1;
        vector<vector<int>> buckets(cnt, vector<int>{});
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - minVal) / len;
            if (buckets[idx].empty()) {
                buckets[idx].resize(2, nums[i]);
            } else {
                buckets[idx][0] = min(buckets[idx][0], nums[i]);
                buckets[idx][1] = max(buckets[idx][1], nums[i]);
            }
        }

        int gap = 0;
        int prev = 0;
        for (int i = 1; i < cnt; i++) {
            if (buckets[i].empty()) {
                continue;
            }
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};
