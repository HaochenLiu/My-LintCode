/*
515. Paint House

There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.

Have you met this question in a real interview? Yes
 Notice

All costs are positive integers.

Example
Tags
Related Problems
 Notes
Given costs = [[14,2,11],[11,14,5],[14,3,10]] return 10

house 0 is blue, house 1 is green, house 2 is blue, 2 + 5 + 3 = 10
*/

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        if(n == 0) return 0;
        int dp[n][3];

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];

        for(int i = 0; i < n - 1; i++) {
            dp[i + 1][0] = costs[i + 1][0] + min(dp[i][1], dp[i][2]);
            dp[i + 1][1] = costs[i + 1][1] + min(dp[i][0], dp[i][2]);
            dp[i + 1][2] = costs[i + 1][2] + min(dp[i][0], dp[i][1]);
        }
        
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};
