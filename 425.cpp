/*
425. Letter Combinations of a Phone Number

Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.
Cellphone

Have you met this question in a real interview? Yes
Example
Given "23"

Return ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]

Note
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
private:
    vector<string> let {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> dfs(string& digits, int idx) {
        vector<string> res;
        if(idx == -1) {
            res.push_back("");
            return res;
        }
        int n = digits.size();
        vector<string> v = dfs(digits, idx - 1);
        for(int i = 0; i < let[digits[idx] - '2'].size(); i++) {
            for(int j = 0; j < v.size(); j++) {
                string t = v[j];
                t.append(1, let[digits[idx] - '2'][i]);
                res.push_back(t);
            }
        }
        return res;
    }
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        int n = digits.size();
        vector<string> res;
        if(n == 0) return res;
        res = dfs(digits, n - 1);
        sort(res.begin(), res.end());
        return res;
    }
};
