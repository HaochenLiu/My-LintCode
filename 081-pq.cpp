/*
081. Data Stream Median

Numbers keep coming, return the median of numbers at every time a new number added.
Have you met this question in a real interview?
Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].
For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].
For numbers coming list: [2, 20, 100], return [2, 2, 20].
Challenge
Total run time in O(nlogn).
Clarification
What's the definition of Median? - Median is the number that in the middle of a sorted array. If there are n numbers in a sorted array A, the median is A[(n - 1) / 2]. For example, if A=[1,2,3], median is 2. If A=[1,19], median is 1.
*/

/*
less 大顶堆
greater 小顶堆
*/

#include <queue>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, less<int> > small;
        priority_queue<int, vector<int>, greater<int> > large;
        vector<int> res;

        small.push(INT_MIN);
        large.push(INT_MAX);
        for(int i = 0; i < n; ++i) {
            if(i & 1) {
                large.push(nums[i]);
            } else {
                small.push(nums[i]);
            }
            int vs = small.top();
            int vl = large.top();
            if(vs > vl) {
                small.pop();
                small.push(vl);
                large.pop();
                large.push(vs);
            }
            res.push_back(small.top());
        }
        return res;
    }
};
