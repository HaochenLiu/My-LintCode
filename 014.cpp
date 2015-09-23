/*
014. Binary Search

For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
If the target number does not exist in the array, return -1.
Have you met this question in a real interview?
Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int n = array.size();
        if(target < array[0]) return -1;
        if(target == array[0]) return 0;
        if(target > array[n - 1]) return -1;
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(array[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        if(array[right] == target) {
            return right;
        }
        
        return -1;
    }
};
