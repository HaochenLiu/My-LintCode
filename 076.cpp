/*
076. Longest Increasing Subsequence

Given a sequence of integers, find the longest increasing subsequence (LIS).
You code should return the length of the LIS.
Have you met this question in a real interview?
Example
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3
For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4
Challenge
Time complexity O(n^2) or O(nlogn)
Clarification
What's the definition of longest increasing subsequence?
    * The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.  
    * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/

class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        vector<int> v;
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        v.push_back(nums[0]);
        int i, j;
        for (i = 1; i < n; ++i) {
            if (nums[i] >= v.back()) {
                v.push_back(nums[i]);
                continue;
            }
            j = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v[j] = nums[i];
        }
        return v.size();
    }
};
