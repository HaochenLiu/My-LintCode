/*
039. Recover Rotated Sorted Array

Given a rotated sorted array, recover it to sorted array in-place.
Have you met this question in a real interview?
Example
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]
Challenge
In-place, O(1) extra space and O(n) time.
Clarification
What is rotated array?
For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    void recoverRotatedSortedArray(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) return;

        int i;
        for (i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                break;
            }
        }
        if (i == n - 1) {
            return;
        }
        reverse(nums.begin(), nums.begin() + i + 1);
        reverse(nums.begin() + i + 1, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
