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
        vector<int> v(4, 0);
        int n = nums.size();

        sort(nums.begin(), nums.end());
        for (int i1 = 0; i1 < n - 3; i1++) {
            for (int i4 = i1 + 3; i4 < n; i4++) {
                int i2 = i1 + 1;
                int i3 = i4 - 1;
                while (i2 < i3) {
                    if (nums[i1] + nums[i2] + nums[i3] + nums[i4] < target) {
                        i2++;
                    } else if (nums[i1] + nums[i2] + nums[i3] + nums[i4] > target) {
                        i3--;
                    } else {
                        v[0] = nums[i1];
                        v[1] = nums[i2];
                        v[2] = nums[i3];
                        v[3] = nums[i4];
                        string s = calcSign(v);
                        if (us.find(s) == us.end()) {
                            ans.push_back(v);
                            us.insert(s);
                        }
                        i2++;
                    }
                }
            }
        }
        us.clear();
        return ans;
    }
private:
    unordered_set<string> us;
    vector<vector<int> > ans;
   
    string calcSign(vector<int> &v) {
        int n = v.size();
        string s = "";
        int i;
        for(i = 0; i < n; i++) {
            s += to_string(v[i]);
            s += " ";
        }
        return s;
    }
};
