/*
075. Find Peak Element

There is an integer array which has the following features:
The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:
A[P] > A[P-1] && A[P] > A[P+1]


Find a peak element in this array. Return the index of the peak.
Have you met this question in a real interview?
Example
Given [1, 2, 1, 3, 4, 5, 7, 6]
Return index 1 (which is number 2) or 6 (which is number 7)
Note
The array may contains multiple peeks, find any of them.
Challenge
Time complexity O(logN)
*/

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        int n = A.size();
        int left = 1;
        int right = n - 2;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(A[mid] >= A[mid - 1] && A[mid] >= A[mid + 1]) {
                return mid;
            } else if(A[mid] < A[mid - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
};
