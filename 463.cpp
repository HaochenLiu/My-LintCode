/*
463. Sort Integers

Given an integer array, sort it in ascending order. Use selection sort, bubble sort, insertion sort or any O(n2) algorithm.

Have you met this question in a real interview? Yes
Example
Given [3, 2, 1, 4, 5], return [1, 2, 3, 4, 5].
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        int n = A.size();
        if(n < 2) return;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(A[i] > A[j]) {
                    swap(A[i], A[j]);
                }
            }
        }
    }
};
