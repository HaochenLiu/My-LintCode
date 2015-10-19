/*
391. Number of Airplanes in the Sky

Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?
Have you met this question in a real interview?
Example
For interval list [[1,10],[2,3],[5,8],[4,7]], return 3
Note
If landing and flying happens at the same time, we consider landing should happen at first.
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
bool compare(Interval interval1, Interval interval2) {
    return interval1.start < interval2.start;
}

class Solution {
private:
    int findNonOverlapping(vector<vector<Interval>>& rooms, Interval& interval) {
        int n = rooms.size();
        for (int i = 0; i < n; i++) {
            if (interval.start >= rooms[i].back().end) {
                return i;
            }
        }

        return -1;
    }

public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<Interval>> rooms;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            int idx = findNonOverlapping(rooms, intervals[i]);
            if (rooms.empty() || idx == -1) {
                rooms.push_back({intervals[i]});
            } else {
                rooms[idx].push_back(intervals[i]);
            }
        }
        return rooms.size();
    }
};
