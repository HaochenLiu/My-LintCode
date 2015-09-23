/*
004. Ugly Number

Ugly number is a number that only have factors 3, 5 and 7.
Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...
Have you met this question in a real interview?
Example
If K=4, return 9.
Challenge
O(K log K) or O(K) time.
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        // write your code here
        if(k == 1) return 3;
        if(k == 2) return 5;
        if(k == 3) return 7;

        vector<long long> res;
        res.push_back(1);
        int idx3 = 0;
        int idx5 = 0;
        int idx7 = 0;

        for(int i = 1; i <= k; i++) {
            long long tmp3 = res[idx3] * 3;
            long long tmp5 = res[idx5] * 5;
            long long tmp7 = res[idx7] * 7;
            long long minVal = min(tmp3, min(tmp5, tmp7));
            res.push_back(minVal);
            if(tmp3 == minVal) {
                idx3++;
            }
            
            if(tmp5 == minVal) {
                idx5++;
            }
            
            if(tmp7 == minVal) {
                idx7++;
            }
        }

        return res[k];
    }
};
