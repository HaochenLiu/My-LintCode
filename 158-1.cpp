/*
158. Two Strings Are Anagrams

Write a method anagram(s,t) to decide if two strings are anagrams or not.
Have you met this question in a real interview?
Example
Given s="abcd", t="dcab", return true.
Challenge
O(n) time, O(1) extra space
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        // write your code here
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return (s == t);
    }
};
