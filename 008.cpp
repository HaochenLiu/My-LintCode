/*
008. Rotate String

Given a string and an offset, rotate string by offset. (rotate from left to right)
Have you met this question in a real interview?
Example
Given "abcdefg".
offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"


Challenge
Rotate in-place with O(1) extra memory.
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        //wirte your code here
        if (str == "") return;
        offset %= str.size();
        if (offset == 0) return;
        reverse(str.begin(), str.begin() + str.size() - offset);
        reverse(str.begin() + str.size() - offset, str.end());
        reverse(str.begin(), str.end());
        return;
    }
};
