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

/*
union-find:
union: amortized O(1)
find: amortized O(1)

Time: O(nm)
Space: O(nm)
Extra space: O(nm)
*/

class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int find(vector<int>& father, int a) {
        if(father[a] == -1) {
            father[a] = a;
            return a;
        }
        while(father[a] != a) {
            a = father[a];
        }
        return a;
    }

    bool inBound(int x, int y, int n, int m) {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> father(n * m, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue;
                int t = i * m + j;
                int ft = find(father, t);
                for(int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(!inBound(nx, ny, n, m)) continue;
                    if(grid[nx][ny] == 0) continue;
                    int nt = nx * m + ny;
                    ft = find(father, t);
                    int fnt = find(father, nt);
                    father[ft] = min(ft, fnt);
                    father[fnt] = min(ft, fnt);
                }
            }
        }

        unordered_set<int> s;
        for(int i = 0; i < n * m; i++) {
            if(father[i] == -1) continue;
            s.insert(find(father, i));
        }
        
        return s.size();
    }
};
