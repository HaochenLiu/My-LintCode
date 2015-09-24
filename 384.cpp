/*
384. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.
Have you met this question in a real interview?
Example
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
Challenge
O(n) time
*/

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        // write your code here
        bool exist[256];
        memset(exist, false, sizeof(exist));
        int res = 0;
        int start = 0, end = 0, N = s.size();
        while (end < N && start + res < N)
        {
            if (!exist[s[end]]) {
                exist[s[end++]] = true;
            } else {
                exist[s[start++]] = false;
            }
            res = max(end - start, res);
        }
        return res;
    }
};
