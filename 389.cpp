/*
389. Valid Sudoku

Determine whether a Sudoku is valid.
The Sudoku board could be partially filled, where empty cells are filled with the character ..
Have you met this question in a real interview?
Example
The following partially filed sudoku is valid.

Note
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
Clarification
What is Sudoku?
http://sudoku.com.au/TheRules.aspx
https://zh.wikipedia.org/wiki/%E6%95%B8%E7%8D%A8
https://en.wikipedia.org/wiki/Sudoku
http://baike.baidu.com/subview/961/10842669.htm
*/

#include <cmath>
using namespace std;

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char> >& board) {
        int n2 = board.size();
        int n = (int)sqrt(n2);
        vector<vector<bool> > row;
        vector<vector<bool> > col;
        vector<vector<bool> > block;
       
        row.resize(n2, vector<bool>(n2, false));
        col.resize(n2, vector<bool>(n2, false));
        block.resize(n2, vector<bool>(n2, false));
       
        int i, j;
        int idx;
        for (i = 0; i < n2; ++i) {
            for (j = 0; j < n2; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                idx = board[i][j] - '1';
                if (row[i][idx]) {
                    return false;
                }
                row[i][idx] = true;
                if (col[j][idx]) {
                    return false;
                }
                col[j][idx] = true;
                if (block[i / n * n + j / n][idx]) {
                    return false;
                }
                block[i / n * n + j / n][idx] = true;
            }
        }
        return true;               
    }
};
