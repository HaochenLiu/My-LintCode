/*
084. Single Number III

Given 2*n + 2 numbers, every numbers occurs twice except two, find them.
Have you met this question in a real interview?
Example
Given [1,2,2,3,4,4,5,3] return 1 and 5
Challenge
O(n) time, O(1) extra space.
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int n = A.size();
        int AxorB = 0;
        for(int i = 0; i < n; i++) {
            AxorB ^= A[i];
        }
        
        int a = 0;
        int b = 0;
        AxorB &= (~(AxorB - 1));
        for(int i = 0; i < n; i++) {
            if(A[i] & AxorB) {
                a ^= A[i];
            } else {
                b ^= A[i];
            }
        }

        return vector<int>{a, b};
    }
};
