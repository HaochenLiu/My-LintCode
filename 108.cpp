/*
108. Palindrome Partitioning II

Given a string s, cut s into some substrings such that every substring is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
Have you met this question in a real interview?
Example
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s a string
     * @return an integer
     */
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) {
            return 0;
        }
        vector<vector<bool> > pal;
        pal.resize(n, vector<bool>(n, false));
        int i, j;
        for (i = 0; i < n; ++i) {
            pal[i][i] = true;
        }
        for (i = 0; i < n - 1; ++i) {
            pal[i][i + 1] = s[i] == s[i + 1];
        }
        for (i = 2; i < n; ++i) {
            for (j = 0; j + i < n; ++j) {
                pal[j][j + i] = s[j] == s[j + i] && pal[j + 1][j + i - 1];
            }
        }
        
        vector<int> dp;
        dp.resize(n);
        for (i = 0; i < n; ++i) {
            dp[i] = i + 1;
            if (pal[0][i]) {
                dp[i] = 1;
                continue;
            }
            for (j = 0; j < i; ++j) {
                if (pal[j + 1][i]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1] - 1;
    }
};
