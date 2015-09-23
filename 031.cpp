/*
031. Partition Array

Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:
All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.
Have you met this question in a real interview?
Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.
Note
You should do really partition in array nums instead of just counting the numbers of integers smaller than k.
If all elements in nums are smaller than k, then return nums.length
Challenge
Can you partition the array in-place and in O(n)?
*/

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            while(nums[i] < k && i < j) {
                i++;
            }
            while(nums[j] >= k && i < j) {
                j--;
            }
            if(i >= j) {
                break;
            }
            swap(nums[i], nums[j]);
        }
        
        if(nums[i] >= k) {
            return i;
        } else {
            return n;
        }
    }
};
