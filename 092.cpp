/*
092. Backpack

Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack?
Have you met this question in a real interview?
Example
If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.
You function should return the max size we can fill in the given backpack.
Note
You can not divide any item into small pieces.
Challenge
O(n x m) time and O(m) memory.
O(n x m) memory is also acceptable if you do not know how to optimize memory.
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        vector<bool> dp;
        dp.resize(m + 1, false);
        dp[0] = true;
        
        int n = A.size();
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = m; j >= A[i]; j--) {
                if (dp[j - A[i]]) {
                    dp[j] = true;
                }
            }
        }
        i = m;
        while (!dp[i]) {
            i--;
        }
        return i;
    }
};
