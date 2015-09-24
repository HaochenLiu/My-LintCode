/*
149. Best Time to Buy and Sell Stock

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Have you met this question in a real interview?
Example
Given an example [3,2,3,1,2], return 1
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }
        int minVal = prices[0];
        int ans = 0;
        int i;
        for (i = 1; i < n; ++i) {
            minVal = min(minVal, prices[i]);
            ans = max(ans, prices[i] - minVal);
        }
        return ans;
    }
};
