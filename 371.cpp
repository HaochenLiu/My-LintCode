/*
371. Print Numbers by Recursion

Print numbers from 1 to the largest number with N digits by recursion.
Have you met this question in a real interview?
Example
Given N = 1, return [1,2,3,4,5,6,7,8,9].
Given N = 2, return [1,2,3,4,5,6,7,8,9,10,11,12,...,99].
Note
It's pretty easy to do recursion like:
recursion(i) {
    if i > largest number:
        return
    results.add(i)
    recursion(i + 1)
}


however this cost a lot of recursion memory as the recursion depth maybe very large. Can you do it in another way to recursive with at most N depth?
Challenge
Do it in recursion, not for-loop.
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        ans.clear();
        DFS(0, 0, n);
        return ans;
    }
private:
    vector<int> ans;
    
    void DFS(int num, int idx, int n) {
        if(idx == n) {
            if(num > 0) {
                ans.push_back(num);
            }
            return;
        }
        
        for(int i = 0; i < 10; i++) {
            DFS(num * 10 + i, idx + 1, n);
        }
    }
};
