/*
434. Number of Islands II

Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.
Have you met this question in a real interview?
Example
Given n = 3, m = 3, array of pair A = [(0,0),(0,1),(2,2),(2,1)].
return [1,1,2,2].
Note
0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.
*/

/**
* Definition for a point.
* struct Point {
*     int x;
*     int y;
*     Point() : x(0), y(0) {}
*     Point(int a, int b) : x(a), y(b) {}
* };
*/
class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // Write your code here
        vector<int> res;
        if(n == 0 || m == 0) return res;
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> father(n * m, -1);
        int sz = operators.size();
        for(int i = 0; i < sz; i++) {
            int x = operators[i].x;
            int y = operators[i].y;
            grid[x][y] = 1;
            int t = x * m + y;
            int ft = find(father, t);
            if(i == 0) {
                res.push_back(1);
                continue;
            }
            unordered_set<int> s;
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nt = nx * m + ny;
                if(!inBound(nx, ny, n, m)) continue;
                if(grid[nx][ny] == 0) continue;
                s.insert(find(father, nt));
            }
            res.push_back(res.back() + 1 - s.size());

            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nt = nx * m + ny;
                if(!inBound(nx, ny, n, m)) continue;
                if(grid[nx][ny] == 0) continue;
                ft = find(father, t);
                int fnt = find(father, nt);
                father[ft] = min(ft, fnt);
                father[fnt] = min(ft, fnt);
            }
        }

        return res;
    }
    
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
};
