/*
047. Majority Number II

Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.
Find it.
Have you met this question in a real interview?
Example
Given [1, 2, 1, 2, 1, 3, 3], return 1.
Note
There is only one majority number in the array.
Challenge
O(n) time and O(1) extra space.
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        vector<int> &a = nums;
        int n = a.size();
        int a1 = 0;
        int a2 = 0;
        int c1 = 0;
        int c2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(a1 == a[i]) {
                c1++;
            } else if(a2 == a[i]) {
                c2++;
            } else if(c1 == 0) {
                a1 = a[i];
                c1 = 1;
            } else if(c2 == 0) {
                a2 = a[i];
                c2 = 1;
            } else {
                c1--;
                c2--;
            }
        }

        c1 = 0;
        c2 = 0;
        for(int i = 0; i < n; i++) {
            if(a1 == a[i]) {
                c1++;
            } else if(a2 == a[i]) {
                c2++;
            }
        }
        if(c1 > n / 3) {
            return a1;
        }
        if(c2 > n / 3) {
            return a2;
        }
    }
};
