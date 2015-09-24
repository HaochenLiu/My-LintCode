/*
187. Gas Station

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Have you met this question in a real interview?
Example
Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.
Note
The solution is guaranteed to be unique.
Challenge
O(n) time and O(1) extra space
*/

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // write your code here
        if(gas.size() == 0) return -1;
        int n = gas.size();
        int sum = 0;
        int minIdx = -1;
        int minVal = INT_MAX;
        for(int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
            if(sum <= minVal) {
                minIdx = i;
                minVal = sum;
            }
        }
        if(sum < 0) {
            return -1;
        }
        return (minIdx + 1) % n;
    }
};
