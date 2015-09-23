/*
051. Previous Permutation

Given a list of integers, which denote a permutation.
Find the previous permutation in ascending order.
Have you met this question in a real interview?
Example
For [1,3,2,3], the previous permutation is [1,2,3,3]
For [1,2,3,4], the previous permutation is [4,3,2,1]
Note
The list may contains duplicate integers.
*/

// Time:  O(n)
// Space: O(1)

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        int k = -1, l = 0;

        // Find the last index k before the increasing sequence.
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                k = i;
            }
        }

        if (k >= 0) {
            // Find the largest number which is smaller than the value of the index k,
            // and swap the values.
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] < nums[k]) {
                    l = i;
                }
            }
            swap(nums[k], nums[l]);
        }

        // Reverse the sequence after the index k.
        reverse(nums.begin() + k + 1, nums.end());

        return nums;
    }
};
