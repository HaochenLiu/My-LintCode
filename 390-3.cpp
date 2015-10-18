/*
390. Find Peak Element II

There is an integer matrix which has the following features:
The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if:
A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1]


Find a peak element in this matrix. Return the index of the peak.
Have you met this question in a real interview?
Example
Given a matrix:
[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]


return index of 41 (which is [1,1]) or index of 24 (which is [2,2])
Note
The matrix may contains multiple peeks, find any of them.
Challenge
Solve it in O(n+m) time.
If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?
*/

/*
Time:  O(m + n)
Space: O(1)
*/

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> A) {
        int upper = 0, down = A.size() - 1;
        int left = 0, right = A[0].size() - 1;

        while (upper < down && left < right) {
            int height = down - upper + 1;
            int width = right - left + 1;

            // T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2) = ... = O(2m) + O(2n) = O(max(m, n))
            if (width > height) {  // Vertical split.
                int mid_j = left + (right - left) / 2;
                int left_max = 0, central_max = 0, right_max = 0;
                int max_i = -1, max_j = -1;
                for (int i = upper + 1; i < down; ++i) {
                    if (A[i][mid_j] > central_max) {
                        max_i = i, max_j = mid_j;
                        central_max = A[i][mid_j];
                    }
                    left_max = max(left_max, A[i][mid_j - 1]);
                    right_max = max(right_max, A[i][mid_j +  1]);
                }
                if (left_max > central_max && left_max > right_max) {  // Find left.
                    right = mid_j;
                } else if (right_max > central_max && right_max > left_max) {  // Find right.
                    left = mid_j;
                } else {  // Find one peak.
                    return {max_i, max_j};
                }
            } else {  // Horizontal split.
                int mid_i = upper + (down - upper) / 2;
                int upper_max = 0, central_max = 0, down_max = 0;
                int max_i = -1, max_j = -1;
                for (int j = left + 1; j < right; ++j) {
                    if (A[mid_i][j] > central_max) {
                        max_i = mid_i, max_j = j;
                        central_max = A[mid_i][j];
                    }
                    upper_max = max(upper_max, A[mid_i - 1][j]);
                    down_max = max(down_max, A[mid_i + 1][j]);
                }
                if (upper_max > central_max && upper_max > down_max) {  // Find upper.
                    down = mid_i;
                } else if (down_max > central_max && down_max > upper_max) {  // Find down.
                    upper = mid_i;
                } else {  // Find one peak.
                    return {max_i, max_j};
                }
            }

        }
        return {-1, -1}; // Not found.
    }
};
