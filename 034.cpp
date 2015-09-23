/*
034. N-Queens II

Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
Have you met this question in a real interview?
Example
For n=4, there are 2 distinct solutions.
*/

class Solution {
public:
    /**
     * Calculate the total number of distinct N-Queen solutions.
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        vector<int> state(n, -1);
        res = 0;
        helper(state, 0);
        return res;
    }
    
private:
    int res;

    void helper(vector<int>& state, int row) {
        int n = state.size();
        if(row == n) {
            res++;
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(isValid(state, row, col)) {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
        }
    }
    
    bool isValid(vector<int>& state, int row, int col) {
        for(int i = 0; i < row; i++) {
            if(state[i] == col || abs(row - i) == abs(col - state[i])) {
                return false;
            }
        }
        return true;
    }
};
