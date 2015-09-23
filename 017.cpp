/*
017. Subsets

Given a set of distinct integers, return all possible subsets.
Have you met this question in a real interview?
Example
If S = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Note
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
*/

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> record;
        unsigned long long bitmax = (1<<n);
        sort(nums.begin(), nums.end());
        for(unsigned long long bit = 0; bit < bitmax; bit++) {
            record.clear();    
            for(int i = 0; i < n; i++) {
                if((bit>>i) & 1 == 1) {
                    record.push_back(nums[i]);
                }
            }
            res.push_back(record);
        }
        return res;
    }
};
