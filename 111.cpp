/*
111. Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Have you met this question in a real interview?
Example
Given an example n=3 , 1+1+1=2+1=1+2=3
return 3
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        // write your code here
        if(n == 1) return 1;
        if(n == 2) return 2;
        int prev = 1;
        int cur = 2;
        int res = prev + cur;
        for(int i = 2; i < n; i++) {
            res = prev + cur;
            prev = cur;
            cur = res;
        }

        return res;
    }
};
