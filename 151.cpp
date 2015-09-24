/*
151. Best Time to Buy and Sell Stock III

Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Have you met this question in a real interview?
Example
Given an example [4,4,6,1,1,4,2,5], return 6.
Note
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

// O(n) time and O(n) space
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        auto &a = prices;
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        int i;
        vector<int> dl;
        dl.resize(n);
        dl[0] = a[0];
        for (i = 1; i < n; ++i) {
            dl[i] = min(dl[i - 1], a[i]);
        }
        dl[0] = 0;
        for (i = 1; i < n; ++i) {
            dl[i] = max(dl[i - 1], a[i] - dl[i]);
        }
        int ans = dl[n - 1];
        int maxVal = a[n - 1];
        for (i = n - 2; i >= 0; --i) {
            maxVal = max(maxVal, a[i]);
            ans = max(ans, maxVal - a[i] + dl[i]);
        }
        return ans;
    }
};
