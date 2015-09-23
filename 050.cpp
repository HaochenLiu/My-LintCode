/*
050. Product of Array Exclude Itself

Given an integers array A.
Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.
Have you met this question in a real interview?
Example
For A = [1, 2, 3], return [6, 3, 2].
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<long long> res(n, 1);
        if(n < 2) return res;

        for(int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        long long tmp = 1;
        for(int i = n - 2; i >= 0; i--) {
            tmp *= nums[i + 1];
            res[i] *= tmp;
        }
        
        return res;
    }
};
