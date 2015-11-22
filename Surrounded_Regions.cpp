/*
Surrounded Regions

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O''s into 'X''s in that surrounded region.
Have you met this question in a real interview?
Example

X X X X
X O O X
X X O X
X O X X

After capture all regions surrounded by 'X', the board should be:

X X X X
X X X X
X X X X
X O X X
*/

class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool inBound(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

public:
    /**
     * @param board a 2D board containing 'X' and 'O'
     * @return void
     */
    void surroundedRegions(vector<vector<char>>& board) {
        // Write your code here
        if(board.size() < 3 || board[0].size() < 3) return;
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') {
                board[i][0] = 'V';
                q.push(make_pair(i, 0));
            }
            if(board[i][m - 1] == 'O') {
                board[i][m - 1] = 'V';
                q.push(make_pair(i, m - 1));
            }
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                board[0][j] = 'V';
                q.push(make_pair(0, j));
            }
            if(board[n - 1][j] == 'O') {
                board[n - 1][j] = 'V';
                q.push(make_pair(n - 1, j));
            }
        }
        
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!inBound(nx, ny, n, m)) continue;
                if(board[nx][ny] == 'O') {
                    board[nx][ny] = 'V';
                    q.push(make_pair(nx, ny));
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'V') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
