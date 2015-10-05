/*
362. Sliding Window Maximum

Given an array of n integer with duplicate number, and a moving window(size k), move the window at each iteration from the start of the array, find the maximum number inside the window at each moving.
Have you met this question in a real interview?
Example
For array [1, 2, 7, 7, 8], moving window size k = 3. return [7, 7, 8]
At first the window is at the start of the array like this
[|1, 2, 7| ,7, 8] , return the maximum 7;
then the window move one step forward.
[1, |2, 7 ,7|, 8], return the maximum 7;
then the window move one step forward again.
[1, 2, |7, 7, 8|], return the maximum 8;
Challenge
o(n) time and O(k) memory
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        deque<int> d;
        vector<int> res;
        int n = nums.size();
        if(k < 1 || k > n) return res;
        if(k == 1) return nums;

        for(int i = 0; i < k; i++) {
            while(!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
        }
        res.push_back(d.front());
        
        for(int i = k; i < n; i++) {
            if(d.front() == nums[i - k]) {
                d.pop_front();
            }
            while(!d.empty() && d.back() < nums[i]) {
                d.pop_back();
            }
            d.push_back(nums[i]);
            res.push_back(d.front());
        }
        
        return res;
    }
};
