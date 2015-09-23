/*
125. Backpack II

Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?
Have you met this question in a real interview?
Example
Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
Note
You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.
Challenge
O(n x m) memory is acceptable, can you do it in O(m) memory?
*/

// O(n * m) time, O(m) space
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        vector<int> dp;
        int n = A.size();
        int i, j;
        
        dp.resize(m + 1, -1);
        dp[0] = 0;
        for (i = 0; i < n; ++i) {
            for (j = m; j >= A[i]; --j) {
                if (dp[j - A[i]] < 0) {
                    continue;
                }
                dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        int ans = 0;
        for (i = m; i >= 0; --i) {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
