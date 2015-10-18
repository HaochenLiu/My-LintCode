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

class Cell {
public:
    int x;
    int y;
    int value;
   
    Cell(int _x = 0, int _y = 0, int _value = 0):x(_x), y(_y), value(_value) {}
    
    bool operator < (const Cell &c) const {
        return value > c.value;
    }
};

struct pair_hash {
    inline size_t operator()(const pair<int,int> &v) const {
        return v.first * 31 + v.second;
    }
};

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        //corner cases
        if (matrix.empty() || matrix[0].empty())  return INT_MAX;
        int m = matrix.size();
        int n = matrix[0].size();
        if(k == 1) return matrix[0][0];
        if (k > m * n || k <= 0)  return INT_MAX;
        unordered_set<pair<int, int>, pair_hash> visited;
        priority_queue<Cell> minHeap;
        Cell c(0, 0, matrix[0][0]);
        minHeap.push(c);
        visited.insert(make_pair(c.x, c.y));
        for(int i = 0; i < k - 1; i++) {
            Cell minCell = minHeap.top();
            minHeap.pop();
            for(int t = 0; t < 2; t++) {
                int nx = minCell.x + dx[t];
                int ny = minCell.y + dy[t];
                if (inBound(matrix, nx, ny) && visited.find(make_pair(nx, ny)) == visited.end()) {
                    minHeap.push(Cell(nx, ny, matrix[nx][ny]));
                    visited.insert(make_pair(nx, ny));
                }
            }
        }
        return minHeap.top().value;
    }
    
private:
    bool inBound(vector<vector<int>> &matrix, int x, int y) {
        int m = matrix.size();
        int n = matrix[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int dx[2] = {1, 0};
    int dy[2] = {0, 1};
};
