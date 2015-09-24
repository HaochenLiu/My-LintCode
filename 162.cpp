/*
162. Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Have you met this question in a real interview?
Example
Given a matrix
[
  [1,2],
  [0,3]
],


return [ [0,2], [0,0] ]
Challenge
Did you use extra space? A straight forward solution using O(mn) space is probably a bad idea. A simple improvement uses O(m + n) space, but still not the best solution. Could you devise a constant space solution?
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        // write your code here
        int row0 = 1, column0 = 1;
        int m = matrix.size();
        if(m <= 0) return;
        
        int n = matrix[0].size();
        if(n <= 0) return;
 
        for(int i = 0; i < n; ++i) {
            if(matrix[0][i] == 0) {
                row0 = 0;
                break;
            }
        }
        
        for(int j = 0; j < m; ++j) {
            if(matrix[j][0] == 0) {
                column0 = 0;
                break;
            }
        }
 
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
 
        for(int i = 1; i < n; ++i) {
            if(matrix[0][i] == 0) {
                for(int j = 1; j < m; ++j) {
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; ++i) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < n; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
 
        if(row0 == 0) {
            for(int i = 0; i < n; ++i) {
                matrix[0][i] = 0;
            }
        }
        
        if(column0 == 0) {
            for(int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
