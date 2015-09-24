/*
387. The Smallest Difference

Given two array of integers(the first array is array A, the second array is array B), now we are going to find a element in array A which is A[i], and another element in array B which is B[j], so that the difference between A[i] and B[j] (|A[i] - B[j]|) is as small as possible, return their smallest difference.
Have you met this question in a real interview?
Example
For example, given array A = [3,6,7,4], B = [2,8,9,3], return 0
Challenge
O(n log n) time
*/

// O(n * log(n)) solution with O(n) space
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        vector<int> tag;
        vector<int> C;
        
        int na = A.size();
        int nb = B.size();
        int i, j;
        i = j = 0;
        while (i < na && j < nb) {
            if (A[i] < B[j]) {
                C.push_back(A[i++]);
                tag.push_back(0);
            } else {
                C.push_back(B[j++]);
                tag.push_back(1);
            }
        }
        if (i < na) {
            C.push_back(A[i++]);
            tag.push_back(0);
        } else {
            C.push_back(B[j++]);
            tag.push_back(1);
        }
        
        int n = C.size();
        int ans = INT_MAX;
        for (i = 0; i < n - 1; ++i) {
            if (tag[i] ^ tag[i + 1]) {
                ans = min(ans, abs(C[i] - C[i + 1]));
            }
        }
        
        return ans;
    }
};
