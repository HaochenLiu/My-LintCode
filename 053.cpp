/*
053. Reverse Words in a String

Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Have you met this question in a real interview?
Example
Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        // write your code here
        if(s.empty()) return "";
        vector<string> res;
        int beg;
        for(beg = 0; beg < s.size(); beg++) {
            if(!isspace(s[beg])) {
                break;
            }
        }

        if(beg == s.size()) {
            return "";
        }

        int end;
        for(end = s.size() - 1; end >= 0; end--) {
            if(!isspace(s[end])) {
                break;
            }
        }
        
        if(end < 0) {
            return "";
        }

        int ibeg = beg;
        int iend = ibeg + 1;        
        while(ibeg <= end) {
            if(isspace(s[ibeg])) {
                ibeg++;
            } else {
                iend = ibeg + 1;
                while(iend <= end && !isspace(s[iend])) {
                    iend++;
                }
                res.push_back(s.substr(ibeg, iend - ibeg));
                ibeg = iend + 1;
            }
        }

        if(res.empty()) {
            return "";
        }

        reverse(res.begin(), res.end());
        string str = res[0];
        for(int i = 1; i < res.size(); i++) {
            str += " ";
            str += res[i];
        }
        
        return str;
    }
};
