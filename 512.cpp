/*
512. Decode Ways Show result 

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

Have you met this question in a real interview? Yes
Example
Tags
 Notes
Given encoded message 12, it could be decoded as AB (1 2) or L (12).
The number of ways decoding 12 is 2.
*/

class Solution {
public:
    int numDecodings(string& s) {
        if(s.size() == 0) return 0;
        if(s[0] == '0') return 0;

        int dp[3000];
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= s.size(); i ++) {
            if(s[i-1] == '0') {
                if(s[i-2] == '1' || s[i-2] == '2') {
                    dp[i] = dp[i-2];
                } else {
                    return 0;
                }
            } else {
                string str = s.substr(i-2, 2);
                if(atoi(str.c_str()) < 27 && atoi(str.c_str()) > (s[i-1]-'0')) {
                    dp[i] = dp[i-1] + dp[i-2];
                } else {
                    dp[i] = dp[i-1];
                }
            }
        }
        return dp[s.size()];
    }
};
