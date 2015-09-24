/*
152. Combinations

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
Have you met this question in a real interview?
Example
For example,
If n = 4 and k = 2, a solution is:
[[2,4],[3,4],[2,3],[1,2],[1,3],[1,4]]
*/

class Solution {
private:
    vector<vector<int> > ret;
    vector<int> a;

public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    void solve(int dep, int maxDep, int n, int start) {
        if (dep == maxDep) {
            ret.push_back(a);
            return;
        }
        
        for(int i = start; i <= n; i++) {
            a[dep] = i;
            solve(dep + 1, maxDep, n, i + 1);
        }      
    }
    
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        a.resize(k);
        ret.clear();
        solve(0, k, n, 1);
        return ret;
    }
};
