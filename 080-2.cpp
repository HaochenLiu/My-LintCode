/*
080. Median

Given a unsorted array with integers, find the median of it. 
A median is the middle number of the array after it is sorted. 
If there are even numbers in the array, return the N/2-th number after sorted.
Have you met this question in a real interview?
Example
Given [4, 5, 1, 2, 3], return 3
Given [7, 9, 4, 5], return 5
Challenge
O(n) time.
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: An integer denotes the middle number of the array.
     */
    int median(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        return quickSelect(nums, (n - 1) / 2, 0, n - 1);
    }
private:
    int quickSelect(vector<int> &a, int k, int ll, int rr) {
        int i, j;
        int piv;
            
    while (true) {
            if (ll == rr) {
                return a[k];
            }
            i = ll + 1;
            j = rr;
            piv = a[ll];
            while (true) {
                while (i <= j && a[i] < piv) {
                    ++i;
                }
                while (i <= j && a[j] > piv) {
                    --j;
                }
                if (i > j) {
                    break;
                }
                swap(a[i++], a[j--]);
            }
            swap(a[j], a[ll]);
            if (k < j) {
                rr = j - 1;
            } else if (k > j) {
                ll = j + 1;
            } else {
                return a[k];
            }
        }
    }
};
