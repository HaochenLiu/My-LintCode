/*
411. Gray Code

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, find the sequence of gray code. A gray code sequence must begin with 0 and with cover all 2n integers.
Have you met this question in a real interview?
Example
Given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2


Note
For a given n, a gray code sequence is not uniquely defined.
[0,2,3,1] is also a valid gray code sequence according to the above definition.
Challenge
O(2n) time.
*/

class Solution {
public:
    int Power2(int n) {
        return 1 << n;
    }

    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        // Write your code here
        vector<int> res;
        if(n == 0) {
            res.push_back(0);
            return res;
        }
        
        if(n == 1) {
            res.push_back(0);
            res.push_back(1);
            return res;
        }

        res.push_back(0);
        res.push_back(1);

        for(int i = 2; i <= n; ++i) {
            for(int j = Power2(i - 1) - 1; j >= 0; --j) {
                res.push_back(Power2(i - 1) + res[j]);
            }
        }
        
        return res;
    }
};
