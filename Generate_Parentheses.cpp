/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
Have you met this question in a real interview?
Example

Given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        if(n == 0) {
            vector<string> res;
            res.clear();
            res.push_back("");
            return res;
        }

        vector<string> last = generateParenthesis(n - 1);
        vector<string> res;
        res.clear();
        set<string> res1;
        res1.clear();
        for(int i = 0; i < last.size(); ++i) {
            int len = 2 * (n - 1);
            for(int j = 0; j <= len; ++j) {
                string tmp = last[i];
                tmp.insert(j, "()");
                res1.insert(tmp);
            }
        }
        
        for(auto it = res1.begin(); it != res1.end(); it++) {
            res.push_back(*it);
        }
        return res;
    }
};
