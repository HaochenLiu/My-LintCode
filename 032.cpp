/*
032. Minimum Window Substring

Given a string source and a string target, find the minimum window in source which will contain all the characters in target.
Have you met this question in a real interview?
Example
source = "ADOBECODEBANC" target = "ABC" Minimum window is "BANC".
Note
If there is no such window in source that covers all characters in target, return the emtpy string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in source.
Challenge
Can you do it in time complexity O(n) ?
Clarification
Should the characters in minimum window has the same order in target?
    - Not necessary.
*/

#include <cstring>
using namespace std;

class Solution {
public:   
    /**
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        string &s = source;
        string &t = target;
        int tc[256];
        int c[256];
        int cc;
        int ls = s.length();
        int lt = t.length();
        int i, j;
        int mi, mj;
        
        memset(tc, 0, sizeof(tc));
        cc = 0;
        for (i = 0; i < lt; ++i) {
            ++tc[t[i]];
            ++cc;
        }
        
        memset(c, 0, sizeof(c));
        mi = 0;
        mj = ls;
        i = j = 0;
        while (j < ls) {
            if (c[s[j]] < tc[s[j]]) {
                --cc;
            }
            ++c[s[j]];
            if (cc == 0) {
                while (cc == 0) {
                    if (j - i < mj - mi) {
                        mi = i;
                        mj = j;
                    }
                    --c[s[i]];
                    if (c[s[i]] < tc[s[i]]) {
                        ++cc;
                    }
                    ++i;
                }
            }
            ++j;
        }
        
        if (mj == ls) {
            return "";
        } else {
            return s.substr(mi, mj - mi + 1);
        }
    }
};
