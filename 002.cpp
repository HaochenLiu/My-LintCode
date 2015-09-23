/*
002. Trailing Zeros

Write an algorithm which computes the number of trailing zeros in n factorial.
Have you met this question in a real interview?
Example
11! = 39916800, so the out should be 2
Challenge
O(log N) time
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return
    long long trailingZeros(long long n) {
        long long res = 0;
        while(n) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};
