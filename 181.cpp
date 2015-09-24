/*
181. Flip Bits

Determine the number of bits required to flip if you want to convert integer n to integer m.
Have you met this question in a real interview?
Example
Given n = 31 (11111), m = 14 (01110), return 2.
Note
Both n and m are 32-bit integers.
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int t = a ^ b;
        int res = 0;
        while(t) {
            t = (t & (t - 1));
            res++;
        }

        return res;
    }
};
