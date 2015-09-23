/*
033. N-Queens

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
Have you met this question in a real interview?
Example
There exist two distinct solutions to the 4-queens puzzle:
[
    [".Q..", // Solution 1
     "...Q",
     "Q...",
     "..Q."],
    ["..Q.", // Solution 2
     "Q...",
     "...Q",
     ".Q.."]
]
Challenge
Can you do it without recursion?
*/

class Solution {
private:
    bool isValid(vector<string>& board, int x, int y) {
        for(int i = 0; i < x; ++i) {
            if(board[i][y] == 'Q') {
                return false;
            }
        }

        for(int i = 0; i < x; ++i) {
            int j = x + y - i;
            if(j >= 0 && j < board.size() && board[i][j] == 'Q') {
                return false;
            }
            j = i - x + y;
            if(j >= 0 && j < board.size() && board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void solve(vector<vector<string>>& res, vector<string>& board, int x) {
        if(x == board.size()) {
            res.push_back(board);
            return;
        }
        for(int y = 0; y < board.size(); ++y) {
            board[x][y] = 'Q';
            if(isValid(board, x, y)) {
                solve(res, board, x + 1);
            }
            board[x][y] = '.';
        }
    }

public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
        vector<vector<string> > res;
        string str(n, '.');
        vector<string> board(n, str);
        solve(res, board, 0);
        return res;
    }
};
