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
Time:  O(nlogm)
Space: O(1)
*/

class Solution {
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
        while(down > up) {
            int mid = (up + down) / 2;
            int maxVal = A[mid][0];
            int maxIdx = 0;
            for(int j = 1; j < m - 1; j++) {
                if(A[mid][j] > maxVal) {
                    maxVal = A[mid][j];
                    maxIdx = j;
                }
            }
            if(A[mid][maxIdx] < A[mid + 1][maxIdx]) {
                up = mid + 1;
            } else if(A[mid][maxIdx] < A[mid - 1][maxIdx]) {
                down = mid - 1;
            } else {
                res[0] = mid;
                res[1] = maxIdx;
                return res;
            }
        }
        
        int maxVal = A[up][0];
        int maxIdx = 0;
        for(int j = 1; j < m - 1; j++) {
            if(A[up][j] > maxVal) {
                maxVal = A[up][j];
                maxIdx = j;
            }
        }
        res[0] = up;
        res[1] = maxIdx;
        return res;
    }
};
