/*
003. Digit Counts

Count the number of k's between 0 and n. k can be 0 - 9.
Have you met this question in a real interview?
Example
if n=12, k=1 in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        // write your code here
        int res = 0;
        int base = 1;
        while(base <= n){
            int part1 = n / (base * 10);
            if(base > 1 && k == 0 && part1 > 0) {
                part1--;
            }
            part1 *= base;
            int bar = n / base % 10;
            int part2 = 0;
            if(k < bar) {
                part2 = base;
            } else if(k == bar) {
                part2 = n % base + 1;
            }
            if (k == 0 && n < base * 10) {
                part2 = 0;
            }
            res += part1 + part2;
            base *= 10;
        }
        return res;  
    }
};
