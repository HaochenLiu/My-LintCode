/*
157. Unique Characters

Implement an algorithm to determine if a string has all unique characters.
Have you met this question in a real interview?
Example
Given "abc", return true.
Given "aab", return false.
Challenge
What if you can not use additional data structures?
*/

#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        char a[256];
        memset(a, 0, sizeof(a));
        int n = str.length();
        int i;
        for (i = 0; i < n; ++i) {
            if (a[str[i]]) {
                return false;
            }
            a[str[i]] = 1;
        }
        return true;
    }
};
