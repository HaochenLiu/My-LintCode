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
Time: O(nlogn)
Space: O(k)
Extra space: O(k)
*/

class Solution {
private:
    void adjust(map<int, int>& small, int& ns, map<int, int>& large, int& nl) {
        if(small.empty() || large.empty()) return;
        int s = small.rbegin()->first;
        int l = large.begin()->first;
        if(s > l) {
            del(small, s);
            del(large, l);
            small[l]++;
            large[s]++;
        }
    }

    void del(map<int, int>& m, int n) {
        if(m[n] == 1) {
            m.erase(n);
        } else {
            m[n]--;
        }
    }

    void remove(int n, map<int, int>& small, int& ns, map<int, int>& large, int& nl) {
        if(large.find(n) != large.end()) {
            del(large, n);
            nl--;
        } else {
            del(small, n);
            ns--;
        }
        if(ns < nl) {
            int l = large.begin()->first;
            del(large, l);
            nl--;
            small[l]++;
            ns++;
            return;
        }
        
        if(ns > nl + 1) {
            int s = small.rbegin()->first;
            del(small, s);
            ns--;
            large[s]++;
            nl++;
            return;
        }
    }
    
    void add(int n, map<int, int>& small, int& ns, map<int, int>& large, int& nl) {
        if(ns == nl) {
            small[n]++;
            ns++;
        } else {
            large[n]++;
            nl++;
        }
        adjust(small, ns, large, nl);
    }

public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        // write your code here
        map<int, int> small;
        map<int, int> large;
        int n = nums.size();
        vector<int> res;
        if(k > n || k < 1 || n < 1) return res;
        if(k == 1) return nums;
        int ns = 0;
        int nl = 0;
        
        for(int i = 0; i < k; i++) {
            add(nums[i], small, ns, large, nl);
        }
        res.push_back(small.rbegin()->first);

        for(int i = k; i < n; i++) {
            remove(nums[i - k], small, ns, large, nl);
            add(nums[i], small, ns, large, nl);
            res.push_back(small.rbegin()->first);
        }
        
        return res;
    }
};
