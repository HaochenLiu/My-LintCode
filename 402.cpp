/*
402. Continuous Subarray Sum

Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)
Have you met this question in a real interview?
Example
Give [-3, 1, 3, -3, 4], return [1,4].
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        vector<int> resLocal;
        vector<int> resGlobal;
        if(A.empty()) return resLocal;
        int n = A.size();
        int maxLocal = A[0];
        int maxGlobal = A[0];
        resLocal.push_back(0);
        resLocal.push_back(0);
        resGlobal.push_back(0);
        resGlobal.push_back(0);

        for(int i = 1; i < n; i++) {
            if(maxLocal > 0) {
                maxLocal += A[i];
                resLocal[1] = i;
            } else {
                maxLocal = A[i];
                resLocal[0] = i;
                resLocal[1] = i;
            }
            
            if(maxLocal > maxGlobal) {
                resGlobal[0] = resLocal[0];
                resGlobal[1] = resLocal[1];
                maxGlobal = maxLocal;
            }
        }

        return resGlobal;
    }
};
