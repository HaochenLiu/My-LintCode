/*
248. Count of Smaller Number

Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) and an query list. For each query, give you an integer, return the number of element in the array that are smaller that the given integer.
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], and queries [1,8,5], return [0,4,2]
Note
We suggest you finish problem Segment Tree Build and Segment Tree Query II first.
Challenge
Could you use three ways to do it.
Just loop
Sort and binary search
Build Segment Tree and Search.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        int n = queries.size();
        vector<int> res;
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i) {
            int t = lower_bound(A.begin(), A.end(), queries[i]) - A.begin();
            res.push_back(t);
        }

        return res;
    }
};
