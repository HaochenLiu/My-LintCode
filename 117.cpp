/*
117. Jump Game II

Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
Have you met this question in a real interview?
Example
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        if(A.size() < 2) return 0;
        int step = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[0] == 1) {
                A.erase(A.begin());
                step++;
            } else {
                break;
            }
        }
        
        int n = A.size();
        int start = 0;
        int end = n - 1;
        while(start < end) {
            if(A[start] + start >= end) {
                step++;
                end = start;
                start = 0;
            } else {
                start++;
            }
        }
        return step;
    }
};
