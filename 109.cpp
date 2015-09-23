/*
109. Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
Have you met this question in a real interview?
Example
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]


The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if(triangle.size() == 0) return 0;
        int n = triangle.size();
        int res = 0;
        vector<int> tmp(n, 0);
        for(int i = triangle.size() - 1; i >= 0; --i) {
            for(int j = 0; j <= i; ++j) {
                if(i == triangle.size() - 1) {
                    tmp[j] = triangle[i][j];
                } else {
                    tmp[j] = triangle[i][j] + min(tmp[j], tmp[j + 1]);
                }
            }
        }
        return tmp[0];
    }
};
