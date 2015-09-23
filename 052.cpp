/*
052. Next Permutation

Given a list of integers, which denote a permutation.
Find the next permutation in ascending order.
Have you met this question in a real interview?
Example
For [1,3,2,3], the next permutation is [1,3,3,2]
For [4,3,2,1], the next permutation is [1,2,3,4]
Note
The list may contains duplicate integers.
*/

class Solution {
public:
    /**
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
     */
    vector<int> nextPermutation(vector<int> &nums) {
        // write your code here
        int i = nums.size() - 1;
        while(i > 0 && nums[i] <= nums[i - 1]) {
            i--;
        }
        reverse(nums.begin() + i, nums.end());
        if(i == 0) {
            return nums;
        }
        int j = i;
        while(j < nums.size() && nums[j] <= nums[i - 1]) {
            j++;
        }
        swap(nums[j], nums[i - 1]);

        return nums;
    }
};
