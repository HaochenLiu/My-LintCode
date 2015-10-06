/*
433. Number of Islands

Given a boolean 2D matrix, find the number of islands.
Have you met this question in a real interview?
Example
Given graph:
[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]


return 3.
Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // Write your code here
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && !visited[i][j]) {
                    res++;
                    dfs(grid, visited, i, j, n, m);
                }
            }
        }

        return res;
    }
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool inBound(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    
    void dfs(vector<vector<bool>> &grid, vector<vector<bool>>& visited, int x, int y, int n, int m) {
        visited[x][y] = true;
        int nx;
        int ny;
        int i;
        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if(!inBound(nx, ny, n, m)) continue;
            if(grid[nx][ny] && !visited[nx][ny]) {
                dfs(grid, visited, nx, ny, n, m);
            }
        }
    }
};
