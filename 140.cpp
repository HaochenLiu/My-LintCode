/*
140. Fast Power

Calculate the an % b where a, b and n are all 32bit integers.
Have you met this question in a real interview?
Example
For 231 % 3 = 2
For 1001000 % 1000 = 0
Challenge
O(logn)
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        // write your code here
        if(a == 0 || b == 0 || b == 1) return 0;
        if(a == 1 || n == 0) return 1;
        if(n == 1) return (a % b);
        long long aa = a % b;
        long long tmp = fastPower(a, b, n / 2);
        if(n % 2 == 0) {
            return tmp * tmp % b;
        } else {
            return (tmp * tmp % b) * a % b;
        }        
    }
};
