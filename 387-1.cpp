/*
387. The Smallest Difference

Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.
Have you met this question in a real interview?
Example
For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0
Challenge
O(n log n) time
*/

// O(n * log(n)) solution with O(1) space
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        if (A.size() > B.size()) {
            return smallestDifference(B, A);
        }
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int i, j;
        int ans = INT_MAX;
        int na = A.size();
        int nb = B.size();
        
        for (i = 0; i < na; ++i) {
            j = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            if (j < nb) {
                ans = min(ans, B[j] - A[i]);
            }
            if (j > 0) {
                ans = min(ans, A[i] - B[j - 1]);
            }
        }
        return ans;
    }
};
