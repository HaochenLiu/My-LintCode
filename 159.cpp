/*
159. Find Minimum in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
Have you met this question in a real interview?
Example
Given [4, 5, 6, 7, 0, 1, 2] return 0
Note
You may assume no duplicate exists in the array.
*/

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        if(num.size() == 0) return 0;
        int left = 0;
        int right = num.size() - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(num[mid] < num[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return num[left];
    }
};
