/*
414. Divide Two Integers

Divide two integers without using multiplication, division and mod operator.
If it is overflow, return 2147483647
Have you met this question in a real interview?
Example
Given dividend = 100 and divisor = 9, return 11.
*/

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        // Write your code here
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long long a = dividend;
        long long b = divisor;
        a = abs(a);
        b = abs(b);
        
        long long res = 0;
        while(a >= b) {
            long long t = b;
            long long quo = 1;
            while(a >= t) {
                a -= t;
                res += quo;
                quo <<= 1;
                t <<= 1;
            }
        }
        return ((dividend < 0) ^ (divisor < 0)) ? -res: res;
    }
};
