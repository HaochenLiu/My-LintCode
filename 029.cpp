/*
029. Interleaving String

Given three strings: s1, s2, s3, determine whether s3 is formed by the interleaving of s1 and s2.
Have you met this question in a real interview?
Example
For s1 = "aabcc", s2 = "dbbca"
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
Challenge
O(n2) time or better
*/

class Solution {
private:
    bool f[1000][1000];
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        // write your code here
        if (s1.size() + s2.size() != s3.size()) return false;
            
        f[0][0] = true;
        for(int i = 1; i <= s1.size(); i++) {
            f[i][0] = f[i - 1][0] && (s3[i - 1] == s1[i - 1]);
        } 
        for(int j = 1; j <= s2.size(); j++) {
            f[0][j] = f[0][j-1] && (s3[j-1] == s2[j-1]);
        }   
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                f[i][j] = (f[i][j-1] && s2[j-1] == s3[i+j-1]) || (f[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
                
        return f[s1.size()][s2.size()];
    }
};
