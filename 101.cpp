/*
101. Remove Duplicates from Sorted Array II

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array A = [1,1,1,2,2,3],
Your function should return length = 5, and A is now [1,1,2,2,3].
Have you met this question in a real interview?
Example
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        if(n < 3) return n;
        int len = 1;
        int cnt = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[len - 1]) {
                if(cnt != 2) {
                    nums[len] = nums[i];
                    cnt++;
                    len++;
                }
            } else {
                nums[len] = nums[i];
                cnt = 1;
                len++;
            }
        }
        
        return len;
    }
};
