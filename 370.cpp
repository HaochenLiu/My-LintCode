/*
370. Convert Expression to Reverse Polish Notation

Given an expression string array, return the Reverse Polish notation of this expression. (remove the parentheses)
Have you met this question in a real interview?
Example
For the expression [3 - 4 + 5] (which denote by ["3", "-", "4", "+", "5"]), return [3 4 - 5 +] (which denote by ["3", "4", "-", "5", "+"])
*/

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> output;
        infixToPostfix(expression, output);
        return output;
    }

    // Convert Infix to Postfix Expression.
    void infixToPostfix(const vector<string>& infix, vector<string>& postfix) {
        stack<string> s;
        for (auto tok : infix) {
            if (atoi(tok.c_str())) {
                postfix.emplace_back(tok);
            } else if (tok == "(") {
                s.emplace(tok);
            } else if (tok == ")") {
                while (!s.empty()) {
                    tok = s.top();
                    s.pop();
                    if (tok == "(") {
                        break;
                    }
                    postfix.emplace_back(tok);
                }
            } else {
                while (!s.empty() && precedence(tok) <= precedence(s.top())) {
                    postfix.emplace_back(s.top());
                    s.pop();
                }
                s.emplace(tok);
            }
        }
        while (!s.empty()) {
            postfix.emplace_back(s.top());
            s.pop();
        }
    }

    int precedence(string x) {
        if (x == "(") {
            return 0;
        } else if (x == "+" || x == "-") {
            return 1;
        } else if (x == "*" || x == "/") {
            return 2;
        }
        return 3;
    }
};
