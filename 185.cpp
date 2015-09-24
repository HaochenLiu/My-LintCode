/*
185. Matrix Zigzag Traversal

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.
Have you met this question in a real interview?
Example
Given a matrix:
[
  [1, 2,  3,  4],
  [5, 6,  7,  8],
  [9,10, 11, 12]
]


return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]
*/

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> ans;
        int n, m;
        n = matrix.size();
        if (n == 0) {
            return ans;
        }
        m = matrix[0].size();
        if (m == 0) {
            return ans;
        }
        int i, j;
        int f = 0;
        for (i = 0; i <= n + m - 2; ++i) {
            if (f) {
                for (j = i; j >= 0; --j) {
                    if (i - j < 0 || i - j > n - 1) {
                        continue;
                    }
                    if (j < 0 || j > m - 1) {
                        continue;
                    }
                    ans.push_back(matrix[i - j][j]);
                }
            } else {
                for (j = 0; j <= i; ++j) {
                    if (i - j < 0 || i - j > n - 1) {
                        continue;
                    }
                    if (j < 0 || j > m - 1) {
                        continue;
                    }
                    ans.push_back(matrix[i - j][j]);
                }
            }
            f = !f;
        }
        return ans;
    }
};
