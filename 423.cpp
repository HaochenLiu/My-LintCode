/*
423. Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
Have you met this question in a real interview?
Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<int> st;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] != ')' && s[i] != ']' && s[i] != '}') {
                st.push(s[i]);
            } else if(s[i] == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            } else if(s[i] == ']') {
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            } else {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
