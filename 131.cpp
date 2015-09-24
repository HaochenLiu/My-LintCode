/*
131. Building Outline

Given N buildings in a x-axis，each building is a rectangle and can be represented by a triple (start, end, height)，where start is the start position on x-axis, end is the end position on x-axis and height is the height of the building. Buildings may overlap if you see them from far away，find the outline of them。
An outline can be represented by a triple, (start, end, height), where start is the start position on x-axis of the outline, end is the end position on x-axis and height is the height of the outline.

Have you met this question in a real interview?
Example
Given 3 buildings：
[
  [1, 3, 3],
  [2, 4, 4],
  [5, 6, 1]
]


The outlines are：
[
  [1, 2, 3],
  [2, 4, 4],
  [5, 6, 1]
]


Note
Please merge the adjacent outlines if they have the same height and make sure different outlines cant overlap on x-axis.
*/

#include <algorithm>
#include <map>
using namespace std;

struct Term {
    int x, y;
    int op;
    bool operator < (const Term &t) const {
        if (x != t.x) {
            return x < t.x;
        }
        if (op != t.op) {
            return op < t.op;
        }
        if (op == 0) {
            // Start of a building
            return y > t.y;
        } else {
            // End of a building
            return y < t.y;
        }
    }
};

class Solution {
public:
    /**
     * @param buildings: A list of lists of integers
     * @return: Find the outline of those buildings
     */
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int> > &a = buildings;
        vector<Term> v;
        Term t;
        int n = a.size();
        int i;
        for (i = 0; i < n; ++i) {
            t.x = a[i][0];
            t.y = a[i][2];
            t.op = 0;
            v.push_back(t);
            t.x = a[i][1];
            t.y = a[i][2];
            t.op = 1;
            v.push_back(t);
        }
        sort(v.begin(), v.end());
        
        map<int, int> m;
        vector<int> px, py;
        bool b;
        
        m[0] = 1;
        n = v.size();
        for (i = 0; i < n; ++i) {
            if (v[i].op == 0) {
                // Start of a building
                if (m.rbegin()->first < v[i].y) {
                    px.push_back(v[i].x);
                    py.push_back(v[i].y);
                }
                ++m[v[i].y];
            } else {
                // End of a building
                b = false;
                --m[v[i].y];
                if (m[v[i].y] == 0) {
                    b = v[i].y == m.rbegin()->first;
                    m.erase(v[i].y);
                }
                if (b) {
                    px.push_back(v[i].x);
                    py.push_back(m.rbegin()->first);
                }
            }
        }
        
        n = px.size();
        vector<vector<int> > ans;
        vector<int> seg(3);
        for (i = 0; i < n - 1; ++i) {
            // Ignore all zeros
            if (py[i] == 0) {
                continue;
            }
            seg[0] = px[i];
            seg[1] = px[i + 1];
            seg[2] = py[i];
            ans.push_back(seg);
        }
        
        return ans;
    }
};
