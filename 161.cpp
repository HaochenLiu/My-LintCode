/*
161. Rotate Image

You are given an n x n 2D matrix representing an image. Rotate the image by 90 degrees (clockwise).
Have you met this question in a real interview?
Example
Given a matrix
[
    [1,2],
    [3,4]
]


rotate it by 90 degrees (clockwise), return
[
    [3,1],
    [4,2]
]


Challenge
Do it in-place.
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int>>& matrix) {
        // write your code here
        int n = matrix.size();
        if(n == 0) return;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = t;
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n / 2; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = t;
            }
        }
        
        return;
    }
};
