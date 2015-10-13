/*
107. Word Break

Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.
Have you met this question in a real interview?
Example
Given s = "lintcode", dict = ["lint", "code"].
Return true because "lintcode" can be break as "lint code".
*/

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        // write your code here
        int n = s.length();
        bool dp[n + 1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            for(unordered_set<string>::iterator it = wordDict.begin(); it != wordDict.end(); it++) {
                if(i + it->length() <= n && dp[i + it->length()] && s.substr(i, it->length()) == *it) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
