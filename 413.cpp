/*
413. Reverse Integer

Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).
Have you met this question in a real interview?
Example
Given x = 123, return 321
Given x = -123, return -321
*/

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int x) {
        // Write your code here
        if(x == INT_MIN) return 0;
        
        int res = 0;
        int tmp = abs(x);
        while(tmp != 0) {
            if(res > INT_MAX / 10 || (res == INT_MAX / 10) && tmp % 10 > 7) {
                return 0;
            }
            res *= 10;
            res += (tmp % 10);
            tmp /= 10;
        }
        
        if(x < 0) {
            res = -res;
        }
        return res;
    }
};
