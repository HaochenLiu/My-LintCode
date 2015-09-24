/*
373. Partition Array by Odd and Even

Partition an integers array into odd number first and even number second.
Have you met this question in a real interview?
Example
Given [1, 2, 3, 4], return [1, 3, 2, 4]
Challenge
Do it in-place.
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        int oddCnt = 0;
        int evenCnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 1) {
                oddCnt++;
            } else {
                evenCnt++;
            }
        }
        if(oddCnt == 0 || evenCnt == 0) {
            return;
        }
        
        int i = 0;
        int j = oddCnt;
        while(true) {
            while(i < oddCnt && nums[i] % 2 == 1) {
                i++;
            }
            while(j < n && nums[j] % 2 == 0) {
                j++;
            }
            if(i == oddCnt || j == n) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        
        return;
    }
};
