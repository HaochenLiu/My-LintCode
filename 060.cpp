/*
060. Search Insert Position

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume NO duplicates in the array.
Have you met this question in a real interview?
Example
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
Challenge
O(log(n)) time
*/

class Solution {
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if(n == 0) return 0;
        if(target < A[0]) return 0;
        if(target == A[0]) return 0;
        if(target > A[n - 1]) return n;
        if(target == A[n - 1]) return n - 1;

        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] == target) {
                return mid;
            } else if(A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }
};
