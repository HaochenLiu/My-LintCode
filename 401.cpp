/*
401. Kth Smallest Number in Sorted Matrix

Find the kth smallest number in at row and column sorted matrix.
Have you met this question in a real interview?
Example
Given k = 4 and a matrix:
[
  [1 ,5 ,7],
  [3 ,7 ,8],
  [4 ,8 ,9],
]


return 5
Challenge
O(k log n), n is the maximal number in width and height.
*/

#include <queue>
using namespace std;

vector<vector<int> > *pa;
int n, m;

typedef struct Comp {
    bool operator () (const int &i1, const int &i2) const {
        return (*pa)[i1 / m][i1 % m] > (*pa)[i2 / m][i2 % m];
    }
} Comp;
priority_queue<int, vector<int>, Comp> pq;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        vector<vector<int> > &a = matrix;
        n = a.size();
        m = a[0].size();
        
        pa = &matrix;
        int i, j;
        for (i = 0; i < n; ++i) {
            pq.push(i * m);
        }
        
        int x, y, c;
        int ans;
        for (i = 0; i < k; ++i) {
            c = pq.top();
            pq.pop();
            x = c / m;
            y = c % m;
            ans = a[x][y];
            if (y < m - 1) {
                ++y;
                pq.push(x * m + y);
            }
        }
        
        while (!pq.empty()) {
            pq.pop();
        }
        return ans;
    }
};
