/*
403. Continuous Subarray Sum II

Given an integer array, find a continuous rotate subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone. The answer can be rorate array or non- rorate array)
Have you met this question in a real interview?
Example
Give [3, 1, -100, -3, 4], return [4,1].
*/

class Solution {
private:
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

public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySumII(vector<int>& A) {
        // Write your code here
        vector<int> resMax;
        vector<int> resMin;
        if(A.empty()) return resMax;
        int n = A.size();
        resMax = continuousSubarraySum(A);

        int maxVal = 0;
        for(int i = resMax[0]; i <= resMax[1]; i++) {
            maxVal += A[i];
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += A[i];
            A[i] = -A[i];
        }

        int minVal = 0;
        resMin = continuousSubarraySum(A);
        for(int i = resMin[0]; i <= resMin[1]; i++) {
            minVal -= A[i];
        }

        if(sum == minVal) {
            return resMax;
        } else if(maxVal >= sum - minVal) {
            return resMax;
        } else {
            resMin[0]--;
            resMin[1]++;
            swap(resMin[0], resMin[1]);
            return resMin;
        }
    }
};
