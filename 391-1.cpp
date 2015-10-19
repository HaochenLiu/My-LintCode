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
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        if(airplanes.empty()) return 0;
        int n = airplanes.size();
        map<int, int> m;
        for(int i = 0; i < n; i++) {
            m[airplanes[i].start]++;
            m[airplanes[i].end]--;
        }
        
        int res = 0;
        int cur = 0;
        for(auto it = m.begin(); it != m.end(); it++) {
            cur += it->second;
            res = max(res, cur);
        }
        
        return res;
    }
};
