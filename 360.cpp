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

#include <map>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        small.clear();
        large.clear();
        ns = 0;
        nl = 0;
        
        vector<int> ans;
        int n = nums.size();
        if (n == 0 || k == 0) {
            return ans;
        }
        
        ns = 0;
        nl = 0;
        int s;
        int l;
        int i;
        for(i = 0; i < k - 1; i++) {
            add(nums[i]);
        }
        for(i = k - 1; i < n; i++) {
            add(nums[i]);
            ans.push_back(small.rbegin()->first);
            remove(nums[i - k + 1]);
        }
        return ans;
    }
private:
    map<int, int> small, large;
    int ns;
    int nl;
    
    void del(map<int, int> &m, int x) {
        m[x]--;
        if (m[x] == 0) {
            m.erase(x);
        }
    }
    
    void adjust() {
        if (small.empty() || large.empty()) return;

        int n1, n2;
        n1 = small.rbegin()->first;
        n2 = large.begin()->first;
        if (n1 <= n2) {
            return;
        }
        
        del(small, n1);
        small[n2]++;
        
        del(large, n2);
        large[n1]++;
    }
    
    void add(int x) {
        if (ns == nl) {
            small[x]++;
            ns++;
        } else {
            large[x]++;
            nl++;
        }
        adjust();
    }
    
    void remove(int x) {
        if(small.find(x) != small.end()) {
            del(small, x);
            ns--;
        } else {
            del(large, x);
            nl--;
        }
        if(ns < nl) {
            small[large.begin()->first]++;
            del(large, large.begin()->first);
            ns++;
            nl--;
        } else if(ns > nl + 1) {
            large[small.rbegin()->first]++;
            del(small, small.rbegin()->first);
            ns--;
            nl++;
        }
        adjust();
    }
};
