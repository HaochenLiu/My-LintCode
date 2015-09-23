/*
082. Single Number

Given 2*n + 1 numbers, every numbers occurs twice except one, find it.
Have you met this question in a real interview?
Example
Given [1,2,2,1,3,4,3], return 4
Challenge
One-pass, constant extra space.
*/

class Solution {
public:
    /**
     * @param A: Array of integers.
     * return: The single number.
     */
    int singleNumber(vector<int> &A) {
        // write your code here
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            res ^= A[i];
        }
        
        return res;
    }
};
