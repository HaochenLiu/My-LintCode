/*
018. Subsets II

Given a list of numbers that may has duplicate numbers, return all possible subsets
Have you met this question in a real interview?
Example
If S = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Note
Each element in a subset must be in non-descending order.
The ordering between two subsets is free.
The solution set must not contain duplicate subsets.
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<int> nums(S);
        vector<vector<int>> res;
        vector<int> record;
        res.push_back(record);
        sort(nums.begin(), nums.end());
        findSubsetsWithDup(nums, 0, record, res);
        return res;
    }
    
    void findSubsetsWithDup(vector<int> &nums, int start, vector<int> &record, vector<vector<int>>& res) {
        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) {
                continue;
            }
            record.push_back(nums[i]);
            res.push_back(record);
            findSubsetsWithDup(nums, i + 1, record, res);
            record.pop_back();
        }
    }
};
