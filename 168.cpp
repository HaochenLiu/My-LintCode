/*
168. Burst Balloons Show result 

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.
- You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
- 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Have you met this question in a real interview? Yes
Example
Tags
Related Problems
 Notes
Given [4, 1, 5, 10]
Return 270

nums = [4, 1, 5, 10] burst 1, get coins 4 * 1 * 5 = 20
nums = [4, 5, 10]    burst 5, get coins 4 * 5 * 10 = 200 
nums = [4, 10]       burst 4, get coins 1 * 4 * 10 = 40
nums = [10]          burst 10, get coins 1 * 10 * 1 = 10

Total coins 20 + 200 + 40 + 10 = 270
*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
    
        // rangeValues[i][j] is the maximum # of coins that can be obtained
        // by popping balloons only in the range [i,j]
        vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));
    
        // build up from shorter ranges to longer ranges
        for (int len = 1; len <= N; ++len) {
            for (int start = 1; start <= N - len + 1; ++start) {
                int end = start + len - 1;
                // calculate the max # of coins that can be obtained by
                // popping balloons only the the range [start,end].
                // consider all possible choices of final balloon to pop
                int bestCoins = 0;
                for (int final = start; final <= end; final++) {
                    int coins = rangeValues[start][final - 1] + rangeValues[final + 1][end]; // coins from popping subranges
                    coins += nums[start - 1] * nums[final] * nums[end + 1]; // coins from final pop
                    if (coins > bestCoins) bestCoins = coins;
                }
                rangeValues[start][end] = bestCoins;
            }
        }
        return rangeValues[1][N];
    }
};
