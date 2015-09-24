/*
205. Interval Minimum Number

Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the minimum number between index start and end in the given array, return the result list.
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], and queries [(1,2),(0,4),(2,4)], return [2,1,5]
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
Challenge
O(logN) time for each query
*/

// Solution using sparse table
#include <algorithm>
using namespace std;
/**
* Definition of Interval:
* classs Interval {
*     int start, end;
*     Interval(int start, int end) {
*         this->start = start;
*         this->end = end;
*     }
*/
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // Sparse table
        vector<vector<int> > st;
        int base = 1;
        int n = A.size();
        int m = 1;
        while (base << 1 <= n) {
            base <<= 1;
            ++m;
        }
        base = 1;
        st.resize(m);
        
        int i;
        for (i = 0; i < m; ++i) {
            st[i].resize(n - base + 1);
            base <<= 1;
        }
        
        for (i = 0; i < n; ++i) {
            st[0][i] = A[i];
        }
        
        int j;
        base = 1;
        for (i = 1; i < m; ++i) {
            base <<= 1;
            for (j = 0; j + base <= n; ++j) {
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (base >> 1)]);
            }
        }
        
        m = queries.size();
        int x, y;
        vector<int> ans;
        for (i = 0; i < m; ++i) {
            x = queries[i].start;
            y = queries[i].end;
            base = 1;
            j = 0;
            while (base << 1 <= y - x + 1) {
                base <<= 1;
                ++j;
            }
            ans.push_back(min(st[j][x], st[j][y + 1 - base]));
        }
        return ans;
    }
};
