/*
422. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Have you met this question in a real interview?
Example
Given s = "Hello World", return 5.
Note
A word is defined as a character sequence consists of non-space characters only.
*/

class Solution {
public:
    /**
     * @param s A string
     * @return the length of last word
     */
    int lengthOfLastWord(string &s) {
        int i, j;
        
        j = s.length() - 1;
        while (j >= 0 && s[j] == ' ') {
            --j;
        }
        i = j;
        while (i >= 0 && s[i] != ' ') {
            --i;
        }
        return j - i;
    }
};
