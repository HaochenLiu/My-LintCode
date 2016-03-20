/*
514. Paint Fence

There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.

Have you met this question in a real interview? Yes
 Notice

n and k are non-negative integers.

Example
Tags
Related Problems
 Notes
Given n=3, k=2 return 6

      post 1,   post 2, post 3
way1    0         0       1 
way2    0         1       0
way3    0         1       1
way4    1         0       0
way5    1         0       1
way6    1         1       0
*/

class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0 || k == 0) return 0;
        if(n == 1) return k;
        int diffColorCounts = k * (k - 1);
        int sameColorCounts = k;
          
        for(int i = 2; i < n; i++){
            int tmp = diffColorCounts;
            diffColorCounts = (diffColorCounts + sameColorCounts) * (k - 1);
            sameColorCounts = tmp;
        }
          
        return diffColorCounts + sameColorCounts;
    }
};
