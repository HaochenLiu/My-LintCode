/*
368. Expression Evaluation

Given an expression string array, return the final result of this expression
Have you met this question in a real interview?
Example
For the expression 2*6-(23+7)/(1+2), input is
[
  "2", "*", "6", "-", "(",
  "23", "+", "7", ")", "/",
  (", "1", "+", "2", ")"
],


return 2
Note
The expression contains only integer, +, -, *, /, (, ).
*/

// Time:  O(n)
// Space: O(n)

class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        stack<int> operands;
        stack<string> operators;
        if (expression.empty()) {
            return 0;
        }
        for (int i = expression.size() - 1; i >= 0; --i) {
            if (isdigit(expression[i][0])) {
                operands.emplace(stoi(expression[i]));
            } else if (expression[i] == ")" || expression[i] == "*" ||
                       expression[i] == "/") {
                operators.emplace(expression[i]);
            } else if (expression[i] == "+" || expression[i] == "-") {
                while (!operators.empty() && (operators.top() == "*" ||
                       operators.top() == "/")) {
                     compute(operands, operators);
                }
                operators.emplace(expression[i]);
            } else if (expression[i] == "(") {
                // operators at least one element, i.e. ")".
                while (operators.top() != ")") {
                    compute(operands, operators);
                }
                operators.pop();
            }
        }
        while (!operators.empty()) {
            compute(operands, operators);
        }
        return operands.top();
    }

    void compute(stack<int>& operands, stack<string>& operators) {
        const int left = operands.top();
        operands.pop();
        const int right = operands.top();
        operands.pop();
        const string op = operators.top();
        operators.pop();
        if (op == "+") {
            operands.emplace(left + right);
        } else if (op == "-") {
            operands.emplace(left - right);
        } else if (op == "*") {
            operands.emplace(left * right);
        } else if (op == "/") {
            operands.emplace(left / right);
        }
    }
};
