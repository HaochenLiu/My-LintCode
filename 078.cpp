/*
078. Longest Common Prefix

Given k strings, find the longest common prefix (LCP).
Have you met this question in a real interview?
Example
For strings "ABCD", "ABEF" and "ACEF", the LCP is "A"
For strings "ABCDEFG", "ABCEFG" and "ABCEFA", the LCP is "ABC"
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        // write your code here
        if(strs.size() == 0) return "";
        if(strs.size() == 1) return strs[0];

        string res = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            res = findCommon(res, strs[i]);
        }
        return res;
    }

    string findCommon(string s1, string s2) {
        int n = min(s1.length(), s2.length());
        for(int i = 0; i < n; ++i) {
            if(s1[i] != s2[i]) return s1.substr(0, i);
        }
        return s1.substr(0, n);
    }
};
