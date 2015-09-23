/*
059. 3 Sum Closest

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.
Have you met this question in a real interview?
Example
For example, given array S = {-1 2 1 -4}, and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Note
You may assume that each input would have exactly one solution.
Challenge
O(n^2) time, O(1) extra space
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = nums[0] + nums[1] + nums[2];
        int diff = abs(res - target);

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

                if(nums[i] + nums[j] + nums[k] == target) {
                    return target;
                } else if(nums[i] + nums[j] + nums[k] < target) {
                    if(abs(nums[i] + nums[j] + nums[k] - target) < diff) {
                        res = nums[i] + nums[j] + nums[k];
                        diff = abs(res - target);
                    }
                    j++;
                } else {
                    if(abs(nums[i] + nums[j] + nums[k] - target) < diff) {
                        res = nums[i] + nums[j] + nums[k];
                        diff = abs(res - target);
                    }
                    k--;
                }
            }
        }
        
        return res;
    }
};
