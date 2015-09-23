/*
016. Permutations II

Given a list of numbers with duplicate number in it. Find all unique permutations.
Have you met this question in a real interview?
Example
For numbers [1,2,2] the unique permutations are:
[
    [1,2,2],
    [2,1,2],
    [2,2,1]
]
Challenge
Do it without recursion.
*/

class Solution {
private:
    bool canUse[100];
    int a[100];
    vector<vector<int>> res;
    vector<int> record;
public:
    void dfs(int dep, int maxDep, vector<int> &nums) {
        if (dep == maxDep) {
            res.push_back(record);
            return;
        }
        
        for(int i = 0; i < maxDep; i++) {
            if (canUse[i]) {
                if (i != 0 && nums[i] == nums[i - 1] && canUse[i - 1]) {
                    continue;
                }
                canUse[i] = false;
                record.push_back(nums[i]);
                dfs(dep + 1, maxDep, nums);
                record.pop_back();
                canUse[i] = true;
            }
        }
    }
    
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        // write your code here
        res.clear();
        if(nums.size() == 0) return res;
        record.clear();
        sort(nums.begin(), nums.end());
        memset(canUse, true, sizeof(canUse));
        dfs(0, nums.size(), nums);
        return res;
    }
};
