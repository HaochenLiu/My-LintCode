/*
063. Search in Rotated Sorted Array II

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
Have you met this question in a real interview?
Example
*/

class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if(n == 0) return false;
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(A[mid] == target) {
                return true;
            }
            
            if(A[mid] == A[right]) {
                right --;
            } else if(A[mid] == A[left]) {
                left++;
            } else if(A[mid] < A[right]) {
                if(A[right] >= target && A[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if(A[left] <= target && A[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        
        return false;
    }
};
