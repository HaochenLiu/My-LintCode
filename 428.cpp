/*
428. Pow(x, n)

Implement pow(x, n).
Have you met this question in a real interview?
Example

Pow(2.1, 3) = 9.261
Pow(0, 1) = 0
Pow(1, 0) = 1

Note

You don't need to care about the precision of your answer, it's acceptable if the expected answer and your answer 's difference is smaller than 1e-3.
Challenge

O(logn) time
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double power(double x, int n) {
        if(n == 0) return 1.0;
        double t = power(x, n / 2);
        if(n % 2 == 0) {
            return t * t;
        } else {
            return t * t * x;
        }
    }
    
    double myPow(double x, int n) {
        if(n >= 0) {
            return power(x, n);
        } else {
            double t = 1.0 / power(x, n / 2);
            if(n % 2 == 0) {
                return t * t;
            } else {
                return t * t / x;
            }
        }
    }
};
