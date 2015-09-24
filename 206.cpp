/*
206. Interval Sum

Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the sum number between index start and end in the given array, return the result list.
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], and queries [(0,4),(1,2),(2,4)], return [23,9,20]
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
Challenge
O(logN) time for each query
*/

typedef long long int LL;
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
    vector<LL> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<LL> sum;
        int n = A.size();
        sum.resize(n + 1, 0);
        int i;
        for (i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + A[i];
        }
        vector<LL> ans;
        int m = queries.size();
        for (i = 0; i < m; ++i) {
            ans.push_back(sum[queries[i].end + 1] - sum[queries[i].start]);
        }
        return ans;
    }
};
