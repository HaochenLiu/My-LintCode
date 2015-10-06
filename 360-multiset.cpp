/*
360. Sliding Window Median
Given an array of n integer, and a moving window(size k), move the window at each iteration from the start of the array, find the median of the element inside the window at each moving. (If there are even numbers in the array, return the N/2-th number after sorting the element in the window. )
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], moving window size k = 3. return [2,7,7]
At first the window is at the start of the array like this
[ | 1,2,7 | ,8,5] , return the median 2;
then the window move one step forward.
[1, | 2,7,8 | ,5], return the median 7;
then the window move one step forward again.
[1,2, | 7,8,5 | ], return the median 7;
Challenge
O(nlog(n)) time
*/

/*
less 从小到大排序（正常）
greater 从大到小排序
*/

/*
Time: O(nlogn)
Space: O(k)
Extra space: O(k)
*/

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        multiset<int, greater<int>> small;
        multiset<int, less<int>> large;
        vector<int> res;
        int n = nums.size();
        if(n < 1 || k < 1 || n < k) return res;
        if(k == 1) return nums;
        small.insert(INT_MIN);
        large.insert(INT_MAX);

        for(int i = 0; i < n; i++) {
            if(i >= k) {
                int toDelete = nums[i - k];
                if(large.find(toDelete) != large.end()) {
                    large.erase(large.find(toDelete));
                    if(small.size() > large.size() + 1) {
                        large.insert(*small.begin());
                        small.erase(small.begin());
                    }
                } else {
                    small.erase(small.find(toDelete));
                    if(large.size() > small.size()) {
                        small.insert(*large.begin());
                        large.erase(large.begin());
                    }
                }
            }
            
            if(nums[i] <= *(small.begin())) {
                small.insert(nums[i]);
                if(small.size() > large.size() + 1) {
                    large.insert(*small.begin());
                    small.erase(small.begin());
                }
            } else {
                large.insert(nums[i]);
                if(large.size() > small.size()) {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                }
            }
            
            if(i >= k - 1) {
                res.push_back(*small.begin());
            }
        }
        return res;
    }
};
