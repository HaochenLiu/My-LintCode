/*
369. Convert Expression to Polish Notation

Given an expression string array, return the Polish notation of this expression. (remove the parentheses)
Have you met this question in a real interview?
Example
For the expression [(5 − 6) * 7] (which represented by ["(", "5", "−", "6", ")", "*", "7"]), the corresponding polish notation is [* - 5 6 7] (which the return value should be ["*", "−", "5", "6", "7"]).
Clarification
Definition of Polish Notation:
http://en.wikipedia.org/wiki/Polish_notation
http://baike.baidu.com/view/7857952.htm
*/

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Polish notation of this expression
     */
    vector<string> convertToPN(vector<string> &expression) {
        vector<string> output;
        infixToPrefix(expression, output);
        return output;
    }

    // Convert Infix to Prefix Expression.
    void infixToPrefix(vector<string>& infix, vector<string>& prefix) {
        reverse(infix.begin(), infix.end());
        stack<string> s;
        for (auto& tok : infix) {
            if (atoi(tok.c_str())) {
                prefix.emplace_back(tok);
            } else if (tok == ")") {
                s.emplace(tok);
            } else if (tok == "(") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == ")") {
                        break;
                    }
                    prefix.emplace_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) < precedence(s.top())) {
                    prefix.emplace_back(s.top());
                    s.pop();
                }
                s.emplace(tok);
            }
        }
        while (!s.empty()) {
            prefix.emplace_back(s.top());
            s.pop();
        }
        reverse(prefix.begin(), prefix.end());
    }

    int precedence(string x) {
        if (x == ")") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
