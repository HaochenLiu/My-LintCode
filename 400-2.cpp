/*
400. Maximum Gap

Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Return 0 if the array contains less than 2 elements.
Have you met this question in a real interview?
Example
Given [1, 9, 2, 5], the sorted form of it is [1, 2, 5, 9], the maximum gap is between 5 and 9 = 4.
Note
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Challenge Sort is easy but will cost O(nlogn) time. Try to solve it in linear time and space
*/

// O(n) solution, yet tricky and slow...
#include <climits>
#include <unordered_set>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        vector<int> a;
        unordered_set<int> us;
        int n = nums.size();
        int i;
        for (i = 0; i < n; ++i) {
            us.insert(nums[i]);
        }
        for (auto it = us.begin(); it != us.end(); ++it) {
            a.push_back(*it);
        }
        
        n = a.size();
        if (n < 2) {
            return 0;
        }
        int minVal = INT_MAX;
        for (i = 0; i < n; ++i) {
            minVal = min(minVal, a[i]);
        }
        int maxVal = INT_MIN;
        for (i = 0; i < n; ++i) {
            a[i] -= minVal;
            maxVal = max(maxVal, a[i]);
        }
        int d = maxVal / (n - 1);
        vector<vector<int> > b(n);
        for (i = 0; i < n; ++i) {
            if (b[a[i] / d].empty()) {
                b[a[i] / d].push_back(a[i]);
                b[a[i] / d].push_back(a[i]);
            } else {
                b[a[i] / d][0] = min(b[a[i] / d][0], a[i]);
                b[a[i] / d][1] = max(b[a[i] / d][1], a[i]);
            }
        }
        i = 0;
        int j;
        int ans = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && b[j].empty()) {
                ++j;
            }
            if (j == n) {
                break;
            }
            ans = max(ans, b[j][0] - b[i][1]);
            i = j;
        }
        return ans;
    }
};
