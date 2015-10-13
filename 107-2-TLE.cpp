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
        if(s.empty()) return true;
        if(wordDict.empty()) return false;
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j <= n; j++) {
                if(dp[j]) {
                    string t = s.substr(i, j - i);
                    if(wordDict.find(t) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
};
