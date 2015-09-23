/*
005.  Kth Largest Element

Find K-th largest element in an array.
Have you met this question in a real interview?
Example
In array [9,3,2,4,8], the 3rd largest element is 4.
In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
Note
You can swap elements in the array
Challenge
O(n) time, O(1) extra memory.

https://en.wikipedia.org/wiki/Quickselect
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
    
private:
    int quickSelect(vector<int>& nums, int ll, int rr, int k) {
        if(ll == rr) {
            return nums[k];
        }

        int i = ll + 1;
        int j = rr;
        int piv = nums[ll];
        
        while(true) {
            while(i <= j && nums[i] < piv) {
                i++;
            }
            while(i <= j && nums[j] > piv) {
                j--;
            }
            if(i > j) {
                break;
            }
            swap(nums[i++], nums[j--]);
        }
        swap(nums[ll], nums[j]);

        if(j < k) {
            return quickSelect(nums, j + 1, rr, k);
        } else if(j > k) {
            return quickSelect(nums, ll, j - 1, k);
        } else {
            return nums[j];
        }
    }
};
