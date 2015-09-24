/*
189. First Missing Positive

Given an unsorted integer array, find the first missing positive integer.
Have you met this question in a real interview?
Example
Given [1,2,0] return 3, and [3,4,-1,1] return 2.
Challenge
Your algorithm should run in O(n) time and uses constant space.
*/

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
                i--;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};
