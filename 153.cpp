/*
153. Combination Sum II

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
Have you met this question in a real interview?
Example
For example, given candidate set 10,1,6,7,2,1,5 and target 8,
A solution set is:
[1,7]
[1,2,5]
[2,6]
[1,1,6]
Note
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
*/

class Solution {
private:
    void dfs(vector<vector<int>>& res, vector<int>& record, vector<int>& candidates, int index, int target) {
        if(target == 0) {
            res.push_back(record);
            return;
        }
        if(index == candidates.size()) {
            return;
        }
        if(candidates[index] > target) {
            return;
        }
        dfs(res, record, candidates, index + 1, target);
        record.push_back(candidates[index]);
        dfs(res, record, candidates, index + 1, target - candidates[index]);
        record.pop_back();
    }
    
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // write your code here
        vector<vector<int>> res;
        vector<int> record;
        sort(candidates.begin(), candidates.end());
        dfs(res, record, candidates, 0, target);
        sort(res.begin(), res.end());
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
