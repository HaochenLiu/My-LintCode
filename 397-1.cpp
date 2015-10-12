/*
397. Longest Increasing Continuous subsequence

Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
Have you met this question in a real interview?
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.
For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.
Note
O(n) time and O(1) extra space.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int n = A.size();
        if(n < 3) return n;
        int inc = 1;
        int dec = 1;
        int res = 1;
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i - 1]) {
                inc++;
                res = max(res, inc);
                dec = 1;
            } else if(A[i] < A[i - 1]) {
                dec++;
                res = max(res, dec);
                inc = 1;
            } else {
                dec++;
                res = max(res, dec);
                inc++;
                res = max(res, inc);
            }
        }
        return res;
    }
};
