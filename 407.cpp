/*
407. Plus One

Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
Have you met this question in a real interview?
Example
Given [1,2,3] which represents 123, return [1,2,4].
Given [9,9,9] which represents 999, return [1,0,0,0].
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int> &digits) {
                vector<int> &a = digits;
               
                reverse(a.begin(), a.end());
                int i, n = a.size();
                int c = 0;
                a[0] += 1;
                for (i = 0; i < n; ++i) {
                        a[i] += c;
                        c = a[i] / 10;
                        a[i] %= 10;
                }
                if (c) {
                        a.push_back(c);
                }
                reverse(a.begin(), a.end());
                return a;
    }
};
