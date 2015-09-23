/*
038. Search a 2D Matrix II

Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.
This matrix has the following properties:
    * Integers in each row are sorted from left to right.
    * Integers in each column are sorted from up to bottom.
    * No duplicate integers in each row or column.
Have you met this question in a real interview?
Example
Consider the following matrix:
[
    [1, 3, 5, 7],
    [2, 4, 7, 8],
    [3, 5, 9, 10]
]
Given target = 3, return 2.
Challenge
O(m+n) time and O(1) extra space
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int i = n - 1;
        int j = 0;
        int res = 0;
        while(j < m && i >= 0) {
            if(matrix[i][j] == target) {
                res++;
            }
            
            if(matrix[i][j] >= target) {
                i--;
            } else {
                j++;
            }
        }
        
        return res;
    }
};
