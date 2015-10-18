/*
390. Find Peak Element II

There is an integer matrix which has the following features:
The numbers in adjacent positions are different.
The matrix has n rows and m columns.
For all i < m, A[0][i] < A[1][i] && A[n - 2][i] > A[n - 1][i].
For all j < n, A[j][0] < A[j][1] && A[j][m - 2] > A[j][m - 1].
We define a position P is a peek if:
A[j][i] > A[j+1][i] && A[j][i] > A[j-1][i] && A[j][i] > A[j][i+1] && A[j][i] > A[j][i-1]


Find a peak element in this matrix. Return the index of the peak.
Have you met this question in a real interview?
Example
Given a matrix:
[
  [1 ,2 ,3 ,6 ,5],
  [16,41,23,22,6],
  [15,17,24,21,7],
  [14,18,19,20,10],
  [13,14,11,10,9]
]


return index of 41 (which is [1,1]) or index of 24 (which is [2,2])
Note
The matrix may contains multiple peeks, find any of them.
Challenge
Solve it in O(n+m) time.
If you come up with an algorithm that you thought it is O(n log m) or O(m log n), can you prove it is actually O(n+m) or propose a similar but O(n+m) algorithm?
*/

/*
Time:  O(n + m)
Space: O(1)
*/

class Solution {
private:
    bool isPeak(vector<vector<int>>& A, int x, int y) {
        return (A[x][y] > A[x - 1][y] && A[x][y] > A[x + 1][y] &&
                A[x][y] > A[x][y - 1] && A[x][y] > A[x][y + 1]);
    }

public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> A) {
        // write your code here
        vector<int> res{-1, -1};
        int n = A.size();
        int m = A[0].size();
        if(A.size() < 3 || A[0].size() < 3) return res;
        int up = 1;
        int down = n - 2;
        int left = 1;
        int right = m - 2;

        while(down - up > 1 || right - left > 1) {
            if(down - up > 1) {
                int mid = (up + down) / 2;
                int maxVal = A[mid][left];
                int maxIdx = left;
                for(int j = left + 1; j <= right; j++) {
                    if(A[mid][j] > maxVal) {
                        maxVal = A[mid][j];
                        maxIdx = j;
                    }
                }
                if(A[mid][maxIdx] < A[mid + 1][maxIdx]) {
                    up = mid;
                } else if(A[mid][maxIdx] < A[mid - 1][maxIdx]) {
                    down = mid;
                } else {
                    res[0] = mid;
                    res[1] = maxIdx;
                    return res;
                }
            }

            if(right - left > 1) {
                int mid = (left + right) / 2;
                int maxVal = A[up][mid];
                int maxIdx = up;
                for(int i = up + 1; i <= down; i++) {
                    if(A[i][mid] > maxVal) {
                        maxVal = A[i][mid];
                        maxIdx = i;
                    }
                }
                if(A[maxIdx][mid] < A[maxIdx][mid + 1]) {
                    left = mid;
                } else if(A[maxIdx][mid] < A[maxIdx][mid - 1]) {
                    right = mid;
                } else {
                    res[0] = maxIdx;
                    res[1] = mid;
                    return res;
                }
            }
        }
        
        for(int i = up; i <= down; i++) {
            for(int j = left; j <= right; j++) {
                if(isPeak(A, i, j)) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }

        return res;
    }
};
