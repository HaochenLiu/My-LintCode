/*
139. Subarray Sum Closest

Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.
Have you met this question in a real interview?
Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]
Challenge
O(nlogn) time
*/

// O(n * log(n)) solution
#include <algorithm>
#include <climits>
using namespace std;

typedef struct Term {
    int i;
    int s;
} Term;

bool comp(const Term &t1, const Term &t2)
{
    return t1.s < t2.s;
}

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        int n = nums.size();
        vector<Term> v;
        Term t;
        
        t.i = 0;
        t.s = 0;
        v.push_back(t);
        int i;
        for(i = 0; i < n; i++) {
            t.i = i + 1;
            t.s += nums[i];
            v.push_back(t);
        }
        sort(v.begin(), v.end(), comp);
        
        vector<int> ans(2);
        int sum = INT_MAX;
        for(i = 0; i < n; i++) {
            if(v[i + 1].s - v[i].s < sum) {
                sum = v[i + 1].s - v[i].s;
                ans[0] = min(v[i].i, v[i + 1].i);
                ans[1] = max(v[i].i, v[i + 1].i) - 1;
            }
        }
        return ans;
    }
};
