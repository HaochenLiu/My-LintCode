/*
382. Triangle Count

Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find?
Have you met this question in a real interview?
Example
Given array S = [3,4,6,7], return 3. They are:
[3,4,6]
[3,6,7]
[4,6,7]


Given array S = [4,4,4,4], return 4. They are:
[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        sort(S.begin(), S.end());
        
        int i, j, k;
        int ans = 0;
        int n = S.size();
        
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                k = lower_bound(S.begin() + j + 1, S.end(), S[i] + S[j]) - S.begin();
                ans += k - j - 1;
            }
        }
        return ans;
    }
};
