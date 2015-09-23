/*
061. Search for a Range

Given a sorted array of n integers, find the starting and ending position of a given target value.
If the target is not found in the array, return [-1, -1].
Have you met this question in a real interview?
Example
Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
Challenge
O(log n) time.
*/

class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if(n == 0) return vector<int>{-1, -1};
        if(A[n - 1] < target || A[0] > target) return vector<int>{-1, -1};
        int leftRange = -1;
        int rightRange = -1;
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(A[mid] == target) {
                leftRange = mid;
                right = mid - 1;
            } else if(A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        if(leftRange == -1) {
             return vector<int>{-1, -1};
        }

        left = 0;
        right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(A[mid] == target) {
                rightRange = mid;
                left = mid + 1;
            } else if(A[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if(rightRange == -1) {
             return vector<int>{-1, -1};
        }


        return vector<int>{leftRange, rightRange};
    }
};
