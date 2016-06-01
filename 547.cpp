/*
547. Intersection of Two Arrays

Given two arrays, write a function to compute their intersection.

Notice

Each element in the result must be unique.
The result can be in any order.
Have you met this question in a real interview? Yes
Example
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> result;

        for(int i=0;i<nums1.size();i++) {
            map[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++) {
            if(map[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                map[nums2[i]] = 0;
            }
        }

        return result;
    }
};
