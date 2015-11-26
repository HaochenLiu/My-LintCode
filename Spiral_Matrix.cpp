/*
Spiral Matrix

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
Have you met this question in a real interview?
Example

Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
private:
    int step[4][2];
    vector<int> ret;
    bool canUse[100][100];
    
public:
    void dfs(vector<vector<int> > &matrix, int direct, int x, int y) {
        for(int i = 0; i < 4; i++) {
            int j = (direct + i) % 4;
            int tx = x + step[j][0];
            int ty = y + step[j][1];
            if (0 <= tx && tx < matrix.size() && 0 <= ty && ty < matrix[0].size() && canUse[tx][ty]) {
                canUse[tx][ty] = false;
                ret.push_back(matrix[tx][ty]);                
                dfs(matrix, j, tx, ty);               
            }            
        }
    }
    
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        step[0][0] = 0;
        step[0][1] = 1;
        step[1][0] = 1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = -1;
        step[3][0] = -1;
        step[3][1] = 0;
        ret.clear();
        memset(canUse, true, sizeof(canUse));
        dfs(matrix, 0, 0, -1);
        
        return ret;
    }
};
