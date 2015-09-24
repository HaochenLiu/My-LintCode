/*
141. Sqrt(x)

Implement int sqrt(int x).
Compute and return the square root of x.
Have you met this question in a real interview?
Example
sqrt(3) = 1
sqrt(4) = 2
sqrt(5) = 2
sqrt(10) = 3
Challenge
O(log(x))
*/

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if(x == 0 || x == 1) return x;
        long long val = x;
        long long beg = 1;
        long long end = 50000;
        while(beg < end) {
            long long mid = beg + (end - beg) / 2;
            if(mid * mid == val) {
                return (int)mid;
            } else if(mid * mid > val) {
                end = mid - 1;
            } else {
                if((mid + 1) * (mid + 1) > val) {
                    return (int)mid;
                }
                beg = mid + 1;
            }
        }
        
        return (int)beg;
    }
};
