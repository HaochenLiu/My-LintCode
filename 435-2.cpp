/*
435. Post Office Problem

On one line there are n houses. Give you an array of integer means the the position of each house. Now you need to pick k position to build k post office, so that the sum distance of each house to the nearest post office is the smallest. Return the least possible sum of all distances between each village and its nearest post office.
Have you met this question in a real interview?
Example
Given array a = [1,2,3,4,5], k = 2. return 3.
Challenge
Could you solve this problem in O(n^2) time ?
*/

// Time:  O(n^3)
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
        // Time:  O(n^3)
        // Space: O(n^2)
        vector<vector<int>> cost(n, vector<int>(n, 0));
        computeMinCost(A, cost);

        // DP of sum.
        // Time:  O(k * n^2)
        // Space: O(n)
        // sum[i][j] denotes the smallest sum of
        // picking i + 1 post offices for the first j + 1 houses.
        vector<vector<int>> sum(2, vector<int>(n, INT_MAX));
        for(int j = 0; j < n; j++) {
            sum[0][j] = cost[0][j];
        }
        sum[1][0] = 0;

        for(int i = 1; i < k; i++) {
            for(int j = 1; j < n; j++) {
                for(int r = 0; r < j; r++) {
                    sum[i % 2][j] = min(sum[i % 2][j], sum[(i - 1) % 2][r] + cost[r + 1][j]);
                }
            }
        }
        return sum[(k - 1) % 2][n - 1];
    }

    void computeMinCost(const vector<int>& A, vector<vector<int>>& cost) {
        // Min cost of building a post office between house (i, j).
        // This post office must be in median position.
        const int n = A.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int mid = (i + j) / 2;
                for(int l = i; l < mid; l++) {
                    cost[i][j] += A[mid] - A[l];
                }
                for(int r = mid + 1; r <= j; r++) {
                    cost[i][j] += A[r] - A[mid];
                }
            }
        }
    }
};
