/*
510. Maximal Rectangle

Given a 2D boolean matrix filled with False and True, find the largest rectangle containing all True and return its area.

Have you met this question in a real interview? Yes
Example
Tags
Related Problems
 Notes
Given a matrix:

[
  [1, 1, 0, 0, 1],
  [0, 1, 0, 0, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 1, 1, 1],
  [0, 0, 0, 0, 1]
]
return 6.
*/

class Solution {
private:
    int largestRectangleArea(vector<int> height) {
        height.push_back(0);
        stack<int> stk;
        int i = 0;
        int maxArea = 0;
        while(i < height.size()) {
            if(stk.empty() || height[stk.top()] <= height[i]) {
                stk.push(i++);
            } else {
                int t = stk.top();
                stk.pop();
                maxArea = max(maxArea, height[t] * (stk.empty() ? i: i - stk.top() - 1));
            }
        }
        
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<bool> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> h1(m, 0);
        vector<int> h2(m, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if((i & 1) == 0) {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j]) {
                        h1[j] = 1 + h2[j];
                    } else {
                        h1[j] = 0;
                    }
                }
                res = max(res, largestRectangleArea(h1));
            } else {
                for(int j = 0; j < m; j++) {
                    if(matrix[i][j]) {
                        h2[j] = 1 + h1[j];
                    } else {
                        h2[j] = 0;
                    }
                }
                res = max(res, largestRectangleArea(h2));
            }
        }
        return res;
    }
};
