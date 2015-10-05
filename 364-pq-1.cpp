/*
364. Trapping Rain Water II

Given n x m non-negative integers representing an elevation map 2d where the area of each cell is 1 x 1, compute how much water it is able to trap after raining.

Have you met this question in a real interview?
Example
Given 5*4 matrix
[12,13,0,12]
[13,4,13,12]
[13,8,10,12]
[12,13,12,12]
[13,13,13,13]

return 14.
*/

struct Block {
    int x;
    int y;
    int h;
    bool operator < (const Block &t) const {
        return h > t.h;
    }
};

class Solution {
private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool inBound(int x, int y, int n, int m) {
        return (x >= 0) && (y >= 0) && (x < n) && (y < m);
    }
    
public:
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        // write your code here
        if((heights.size() < 3) || (heights[0].size() < 3)) return 0;
        int n = heights.size();
        int m = heights[0].size();
        Block block;
        priority_queue<Block> pq;
        vector<vector<bool>> flag(n, vector<bool>(m, false));
        for(int i = 0; i < n; i++) {
            Block block;
            block.x = i;
            block.y = 0;
            block.h = heights[i][0];
            pq.push(block);
            flag[i][0] = true;
        }

        for(int i = 0; i < n; i++) {
            Block block;
            block.x = i;
            block.y = m - 1;
            block.h = heights[i][m - 1];
            pq.push(block);
            flag[i][m - 1] = true;
        }

        for(int j = 1; j < m - 1; j++) {
            Block block;
            block.x = 0;
            block.y = j;
            block.h = heights[0][j];
            pq.push(block);
            flag[0][j] = true;
        }

        for(int j = 1; j < m - 1; j++) {
            Block block;
            block.x = n - 1;
            block.y = j;
            block.h = heights[n - 1][j];
            pq.push(block);
            flag[n - 1][j] = true;
        }
        
        int res = 0;
        while(!pq.empty()) {
            Block block = pq.top();
            pq.pop();
            int x = block.x;
            int y = block.y;
            int h = block.h;
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!inBound(nx, ny, n, m)) {
                    continue;
                }
                if(flag[nx][ny]) {
                    continue;
                }
                res += max(0, heights[x][y] - heights[nx][ny]);

                Block nb;
                nb.x = nx;
                nb.y = ny;
                heights[nx][ny] = max(heights[nx][ny], heights[x][y]);
                nb.h = heights[nx][ny];
                pq.push(nb);
                flag[nx][ny] = true;
            }
        }
        
        return res;
    }
};
