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

#include <algorithm>
#include <queue>
using namespace std;

typedef struct Term {
    int i, j, h;
    Term(int _i = 0, int _j = 0, int _h = 0): i(_i), j(_j), h(_h) {}
    
    bool operator < (const Term &t) const {
        return h > t.h;
    }
} Term;

class Solution {
public:
    Solution() {
        offset.resize(4, vector<int>(2));
        offset[0][0] = +1;
        offset[0][1] = 0;
        offset[1][0] = -1;
        offset[1][1] = 0;
        offset[2][0] = 0;
        offset[2][1] = +1;
        offset[3][0] = 0;
        offset[3][1] = -1;
    }
    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        v.clear();
        
        n = heights.size();
        m = n ? heights[0].size() : 0;
        if (n == 0 || m == 0) {
            return 0;
        }
        
        int i, j;
        v.resize(n, vector<bool>(m, false));
        for (i = 0; i < n; ++i) {
            pq.push(Term(i, 0, heights[i][0]));
            v[i][0] = true;
            pq.push(Term(i, m - 1, heights[i][m - 1]));
            v[i][m - 1] = true;
        }
        for (i = 0; i < m; ++i) {
            pq.push(Term(0, i, heights[0][i]));
            v[0][i] = true;
            pq.push(Term(n - 1, i, heights[n - 1][i]));
            v[n - 1][i] = true;
        }
        
        Term t, t1;
        int ans = 0;
        while (!pq.empty()) {
            t = pq.top();
            pq.pop();
            
            for (i = 0; i < 4; ++i) {
                t1.i = t.i + offset[i][0];
                t1.j = t.j + offset[i][1];
                if (!inbound(t1.i, t1.j) || v[t1.i][t1.j]) {
                    continue;
                }
                ans += max(0, t.h - heights[t1.i][t1.j]);
                t1.h = max(t.h, heights[t1.i][t1.j]);
                pq.push(t1);
                v[t1.i][t1.j] = true;
            }
        }
        
        return ans;
    }
private:
    vector<vector<int> > offset;
    int n, m;
    priority_queue<Term> pq;
    vector<vector<bool> > v;
    
    bool inbound(int x, int y) {
        return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1);
    }
};
