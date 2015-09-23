/*
058. 4 Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Have you met this question in a real interview?
Example
For example, given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
Note
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
*/

// Without hashing
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        vector<vector<int> > res;
        res.clear();
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>> > pairs;
        pairs.clear();
        
        for(int i = 0; i < n - 1; ++i) {
            for(int j = i + 1; j < n; ++j) {
                pairs[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }
        
        for(int i = 0; i < n - 3; ++i) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; ++j) {
                if(j != i + 1 && nums[j] == nums[j - 1]) continue;
                if(pairs[target - nums[i] - nums[j]].size() != 0) {
                    vector<pair<int, int> > p = pairs[target - nums[i] - nums[j]];
                    bool first = true;
                    for(int k = 0; k < p.size(); ++k) {
                        if(p[k].first <= j) continue;
                        if(first || res.back()[2] != p[k].first) {
                            res.push_back(vector<int>{nums[i], nums[j], nums[p[k].first], nums[p[k].second]});
                            first = false;
                        }
                    }
                }
            }
        }
        auto pos = unique(res.begin(), res.end());
        res.erase(pos, res.end());
        return res;
    }
};
