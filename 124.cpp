/*
124. Longest Consecutive Sequence

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Have you met this question in a real interview?
Example
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
Clarification
Your algorithm should run in O(n) complexity.
*/

// O(n) time and space
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        vector<int> &a = num;
        unordered_map<int, int> um;
        int n = a.size();
        int i;
        for (i = 0; i < n; ++i) {
            um[a[i]] = 1;
        }
        unordered_map<int, int>::iterator it1, it2;
        it1 = um.begin();
        while (it1 != um.end()) {
            while (true) {
                i = it1->first + it1->second;
                it2 = um.find(i);
                if (it2 == um.end()) {
                    break;
                }
                it1->second += it2->second;
                um.erase(it2);
            }
            ++it1;
        }
        int ans = 0;
        for (it1 = um.begin(); it1 != um.end(); ++it1) {
            ans = max(ans, it1->second);
        }
        return ans;
    }
};
