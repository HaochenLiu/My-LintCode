/*
435. Post Office Problem

On one line there are n houses. Give you an array of integer means the the position of each house. Now you need to pick k position to build k post office, so that the sum distance of each house to the nearest post office is the smallest. Return the least possible sum of all distances between each village and its nearest post office.
Have you met this question in a real interview?
Example
Given array a = [1,2,3,4,5], k = 2. return 3.
Challenge
Could you solve this problem in O(n^2) time ?
*/

// Time:  O(k * n^2)
// Space: O(n^2)

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        const int n = A.size();
        if (A.empty() || k >= n || k <= 0) return 0;
        sort(A.begin(), A.end());

        // Precompute cost.
        // Time:  O(n^2)
        // Space: O(n^2)
        vector<vector<int>> cost(n, vector<int>(n, 0));
        computeMinCost(A, cost);

        // DP of sum.
        // Time:  O(k * n^2)
        // Space: O(nk)
        // sum[i][j] denotes the smallest sum of
        // picking i + 1 post offices for the first j + 1 houses.
        vector<vector<int>> sum(k, vector<int>(n, INT_MAX));
        for(int j = 0; j < n; j++) {
            sum[0][j] = cost[0][j];
        }

        for(int i = 0; i < k; i++) {
            sum[i][0] = 0;
        }

        for(int i = 1; i < k; i++) {
            for(int j = 1; j < n; j++) {
                for(int r = 0; r < j; r++) {
                    sum[i][j] = min(sum[i][j], sum[i - 1][r] + cost[r + 1][j]);
                }
            }
        }
        return sum[k - 1][n - 1];
    }

    void computeMinCost(const vector<int>& A, vector<vector<int>>& cost) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        const int n = A.size();
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }

        for(int i = 0; i < n - 1; i++) {
            cost[i][i + 1] = A[i + 1] - A[i];
        }

        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j <= i && j < n - i; j++) {
                cost[i - j][i + j] = cost[i - j + 1][i + j - 1] + A[i + j] - A[i - j];
            }
        }

        for(int i = 0; i < n - 1; i++) {
            for(int j = 2; j <= i + 1 && j < n - i; j++) {
                cost[i - j + 1][i + j] = cost[i - j + 2][i + j - 1] + A[i + j] - A[i - j + 1];
            }
        }
    }
};
