/*
048. Majority Number III

Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.
Find it.
Have you met this question in a real interview?
Example
Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.
Note
There is only one majority number in the array.
Challenge
O(n) time and O(k) extra space
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        int n = nums.size();
        int i, j;
        vector<int> m;
        vector<int> c;
        
        m.resize(k - 1, 0);
        c.resize(k - 1, 0);
        for(i = 0; i < n; i++) {
            for(j = 0; j < k - 1; j++) {
                if(m[j] == nums[i]) {
                    c[j]++;
                    break;
                }
            }
            if(j < k - 1) {
                continue;
            }
            
            for(j = 0; j < k - 1; j++) {
                if(c[j] == 0) {
                    m[j] = nums[i];
                    c[j] = 1;
                    break;
                }
            }
            if(j < k - 1) {
                continue;
            }
            
            for(j = 0; j < k - 1; j++) {
                c[j]--;
            }
        }
        
        for(i = 0; i < k - 1; i++) {
            c[i] = 0;
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < k - 1; j++) {
                if(nums[i] == m[j]) {
                    c[j]++;
                    break;
                }
            }
        }
        for(i = 0; i < k - 1; i++) {
            if(c[i] > n / k) {
                return m[i];
            }
        }
    }
};
