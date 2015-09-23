/*
058. 4 Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
Have you met this question in a real interview?
Example
For example, given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
Note
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
*/

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        ans.clear();
        vector<int> &a = nums;
        vector<int> v(4);
        int n = nums.size();
        int i1, i2, i3, i4;
        
        sort(a.begin(), a.end());
        i1 = 0;
        while(i1 < n) {
            i4 = n - 1;
            while (i4 > i1) {
                i2 = i1 + 1;
                i3 = i4 - 1;
                while (i2 < i3) {
                    if (a[i1] + a[i2] + a[i3] + a[i4] < target) {
                        ++i2;
                    } else if (a[i1] + a[i2] + a[i3] + a[i4] > target) {
                        --i3;
                    } else {
                        v[0] = a[i1];
                        v[1] = a[i2];
                        v[2] = a[i3];
                        v[3] = a[i4];
                        ans.push_back(v);
                        i2 = nextPos(a, n, i2);
                    }
                }
                i4 = lastPos(a, i1, i4);
            }
            i1 = nextPos(a, n, i1);
        }
        return ans;
    }
private:
    vector<vector<int> > ans;
    
    int lastPos(vector<int> &a, int n, int i) {
        int val = a[i];
        while (i > n && a[i] == val) {
            --i;
        }
        return i;
    }
    
    int nextPos(vector<int> &a, int n, int i) {
        int val = a[i];
        while (i < n && a[i] == val) {
            ++i;
        }
        return i;
    }
};
