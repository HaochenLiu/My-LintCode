/*
114. Unique Paths

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
Have you met this question in a real interview?
Example
1,1
1,2
1,3
1,4
1,5
1,6
1,7
2,1












3,1










3,7

Above is a 3 x 7 grid. How many possible unique paths are there?
Note
m and n will be at most 100.
*/

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        int sum = m + n - 2;
        int maxVal = max(m, n) - 1;
        int minVal = min(m, n) - 1;
        long long res = 1;
        for(int i = 1; i <= minVal; i++) {
            res *= (maxVal + i);
            res /= i;
        }

        return res;
    }
};
