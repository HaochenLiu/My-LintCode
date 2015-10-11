/*
397. Longest Increasing Continuous subsequence

Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)
Have you met this question in a real interview?
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.
For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.
Note
O(n) time and O(1) extra space.
*/

#include <algorithm>
using namespace std;

static bool lt(const int &x, const int &y) {
    return x < y;
}

static bool gt(const int &x, const int &y) {
    return x > y;
}

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        return max(solve(A, lt), solve(A, gt));
    }
    
private:
    int solve(vector<int> &a, bool (*comp)(const int &, const int &)) {
        int n = a.size();
        int ans = 0;
        int i, j;
        i = 0;
        while (i < n) {
            j = i + 1;
            while (j < n && comp(a[j - 1], a[j])) {
                ++j;
            }
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};
