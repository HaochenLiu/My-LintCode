/*
083. Single Number II

Given 3*n + 1 numbers, every numbers occurs triple times except one, find it.
Have you met this question in a real interview?
Example
Given [1,1,2,3,3,3,2,2,4,1] return 4
Challenge
One-pass, constant extra space.
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
        int n = A.size();
        int one = 0;
        int two = 0;
        int three = 0;
        for(int i = 0; i < n; i++) {
            two |= (one & A[i]);
            one ^= A[i];
            three = two & one;
            two &= (~three);
            one &= (~three);
        }

        return one;
    }
};
