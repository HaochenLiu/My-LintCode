/*
393. Best Time to Buy and Sell Stock IV

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.
Have you met this question in a real interview?
Example
Given prices = [4,4,6,1,1,4,2,5], and k = 2, return 6.
Note
You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
Challenge
O(nk) time.
*/

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        if (k >= n) {
            return helper(prices);
        }

        vector<int> max_local(k + 1, 0);
        vector<int> max_global(k + 1, 0);
        int diff;
        for (int i = 0; i < n - 1; i++) {
            diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; j--) {
                max_local[j] = max(max_global[j - 1] + max(diff, 0), max_local[j] + diff);
                max_global[j] = max(max_local[j], max_global[j]);
            }
        }
        return max_global[k];
    }

    int helper(vector<int> &prices) {
        int profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            profit = max(profit, profit + prices[i + 1] - prices[i]);
        }
        return profit;
    }
};
