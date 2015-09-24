/*
200. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
Have you met this question in a real interview?
Example
Given the string = "abcdzdcab", return "cdzdc".
Challenge
O(n2) time is acceptable. Can you do it in O(n) time.
*/

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string& s) {
        // Write your code here
        int n = s.size();
        if(n < 2) return s;
        string str = "#";
        for(int i = 0; i < s.size(); ++i) {
            str.push_back(s[i]);
            str.push_back('#');
        }
        vector<int> dp(str.size(), 0);
        int R = 0;
        int C = 0;
        int len = 0;
        for(int i = 0; i < dp.size(); ++i) {
            if(i < R) {
                dp[i] = min(dp[2 * C - i], R- i);
            } else {
                dp[i] = 1;
            }
            while(i >= dp[i] && i + dp[i] < dp.size() && str[i + dp[i]] == str[i - dp[i]]) {
                dp[i]++;
            }
            dp[i]--;
            
            if(dp[i] > len) {
                len = dp[i];
                C = i;
                R = i + dp[i];
            }
        }
        return s.substr((C - dp[C]) / 2, dp[C]);
    }
};
