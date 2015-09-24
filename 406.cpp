/*
406. Minimum Size Subarray Sum

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return -1 instead.
Have you met this question in a real interview?
Example
Given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.
Challenge
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @param s: an integer
     * @return: an integer representing the minimum size of subarray
     */
    int minimumSize(vector<int> &nums, int s) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        
        int ll, rr;
        int sum;
        int ans = n + 1;
        
        sum = 0;
        ll = 0;
        rr = 0;
        while (rr < n) {
            sum += nums[rr];
            if (sum >= s) {
                ans = min(ans, rr - ll + 1);
                while (ll <= rr && sum - nums[ll] >= s) {
                    sum -= nums[ll];
                    ++ll;
                    ans = min(ans, rr - ll + 1);
                }
            }
            ++rr;
        }
        return ans <= n ? ans : -1;
    }
};
