/*
383. Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Have you met this question in a real interview?
Example
Given [1,3,2], the max area of the container is 2.
Note
You may not slant the container.
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &height) {
        // write your code here
        int i = 0;
        int j = height.size() - 1;
        int res = 0;
        while(i < j)
        {
            int temp = min(height[i], height[j]) * (j - i);
            if(temp > res) {
                res = temp;
            }

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return res;
    }
};
