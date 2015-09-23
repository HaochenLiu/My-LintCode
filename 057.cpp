/*
057. 3 Sum

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Have you met this question in a real interview?
Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2)


Note
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while(j < k) {
                while(j > i + 1 && j < k && nums[j] == nums[j - 1]) {
                    j++;
                }
                while(k < n - 1 && j < k && nums[k] == nums[k + 1]) {
                    k--;
                }
                
                if(j >= k) {
                    break;
                }

                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                } else if(nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        
        return res;
    }
};
