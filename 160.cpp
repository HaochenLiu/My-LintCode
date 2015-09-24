/*
160. Find Minimum in Rotated Sorted Array II

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
Have you met this question in a real interview?
Example Given [4,4,5,6,7,0,1,2] return 0
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        // write your code here
        int n = num.size();
        if(n == 0) return 0;
        int left = 0;
        int right = n - 1;
        int res = num[0];
        while(left <= right) {
            int mid = left + (right - left) / 2;
            res = min(res, num[mid]);
            if(num[mid] < num[right]) {
                right = mid - 1;
            } else if(num[mid] > num[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }
        return res;
    }
};
