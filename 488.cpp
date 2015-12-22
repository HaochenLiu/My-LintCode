/*
488. Happy Number

Write an algorithm to determine if a number is happy.

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Have you met this question in a real interview?
Example

19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
*/

class Solution {
public:
    int trans(int n) {
        int res = 0;
        while(n != 0) {
            int tmp = n % 10;
            res += (tmp * tmp);
            n /= 10;
        }
        return res;
    }

    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        // Write your code here
        unordered_set<int> used;
        int tmp;
        if(n == 1) {
            return true;
        } else {
            used.insert(n);
            tmp = trans(n);
        }
        
        while(tmp != 1) {
            if(used.find(tmp) != used.end()) {
                return false;
            }
            used.insert(tmp);
            tmp = trans(tmp);
        }
        return true;
    }
};
