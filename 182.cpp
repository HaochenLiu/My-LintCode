/*
182. Delete Digits

Given string A representative a positive integer which has N digits, remove any k digits of the number, the remaining digits are arranged according to the original order to become a new positive integer.
Find the smallest integer after remove k digits.
N <= 240 and k <= N,
Have you met this question in a real interview?
Example
Given an integer A = "178542", k = 4
return a string "12"
*/

class Solution {
public:
    /**
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
        string ans = "";
        int n = A.length();
        int c = n - k;
        int i, j;
        
        i = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && k > 0) {
                if (A[j] >= A[i]) {
                    ++j;
                    continue;
                }
                if (k >= j - i) {
                    k -= j - i;
                    i = j;
                }
                ++j;
            }
            ans.push_back(A[i++]);
            if (ans.length() >= c) {
                break;
            }
        }
        i = 0;
        while (i < c - 1 && ans[i] == '0') {
            ++i;
        }
        ans = ans.substr(i, c - i);
        return ans;
    }
};
