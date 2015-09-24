/*
148. Sort Colors

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Have you met this question in a real interview?
Example
Given [1, 0, 1, 2], return [0, 1, 1, 2].
Note
You are not suppose to use the library's sort function for this problem.
Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with an one-pass algorithm using only constant space?
*/

class Solution{
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2
     * @return: nothing
     */   
    void sortColors(vector<int> &nums) {
        auto &a = nums;
        int n = a.size();
        vector<int> c(3, 0);
        int i;
        for (i = 0; i < n; ++i) {
            ++c[a[i]];
        }
        int j, k = 0;
        for (i = 0; i < 3; ++i) {
            for (j = 0; j < c[i]; ++j) {
                a[k++] = i;
            }
        }
    }
};
