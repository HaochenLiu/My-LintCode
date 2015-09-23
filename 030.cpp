/*
030. Insert Interval

Given a non-overlapping interval list which is sorted by start point.
Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).
Have you met this question in a real interview?
Example
Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].
Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].
*/

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
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> &a = intervals;
        Interval b = newInterval;
        int i, n = a.size();
        
        vector<Interval> ans;
        i = 0;
        while (i < n && a[i].end < b.start) {
            ans.push_back(a[i++]);
        }
        while (i < n && b.end >= a[i].start) {
            b.start = min(b.start, a[i].start);
            b.end = max(b.end, a[i].end);
            ++i;
        }
        ans.push_back(b);
        while (i < n) {
            ans.push_back(a[i++]);
        }
        return ans;
    }
};
