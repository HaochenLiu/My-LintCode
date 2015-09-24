/*
143. Sort Colors II

Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.
Have you met this question in a real interview?
Example
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].
Note
You are not suppose to use the library's sort function for this problem.
Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?
*/

// O(1) space, but three passes
// Why bother such a tricky one?
class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */   
    void sortColors2(vector<int> &colors, int k) {
        auto &a = colors;
        int n = a.size();
        int mod = 2 * k + 2;
        
        int i;
        for (i = 0; i < n; ++i) {
            a[a[i] % mod - 1] += mod;
        }
        
        int j, cc;
        int c;
        cc = 0;
        for (i = 0; i < k; ++i) {
            c = a[i] / mod;
            for (j = 0; j < c; ++j) {
                a[cc] = a[cc] / mod * mod + (i + 1);
                ++cc;
            }
        }
        for (i = 0; i < n; ++i) {
            a[i] %= mod;
        }
    }
};
