/*
388. Permutation Sequence

Given n and k, return the k-th permutation sequence.
Have you met this question in a real interview?
Example
For n = 3, all permutations are listed as follows:
"123"
"132"
"213"
"231"
"312"
"321"


If k = 4, the fourth permutation is "231"
Note
n will be between 1 and 9 inclusive.
Challenge
O(n*k) in time complexity is easy, can you do it in O(n^2) or less?
*/

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        string ans = "";
        --k;
        vector<int> v;
        int f = 1;
        int i, j;
        for (i = 1; i < n; ++i) {
            f *= i;
        }
        
        v.resize(n);
        for (i = 0; i < n; ++i) {
            v[i] = i + 1;
        }
        
        int p;
        for (i = n - 1; i >= 1; --i) {
            p = k / f;
            k %= f;
            ans.push_back('0' + v[p]);
            v.erase(v.begin() + p);
            f /= i;
        }
        ans.push_back('0' + v[0]);
        return ans;
    }
};
