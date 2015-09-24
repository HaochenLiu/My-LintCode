/*
249. Count of Smaller Number before itself

Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) . For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], return [0,1,2,3,2]
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query II and Count of Smaller Number before itself I first.
*/

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> s(N + 1, 0);
        vector<int> ans;
        int n = A.size();
        int i;
        for (i = 0; i < n; ++i) {
            // Offset by 1
            ans.push_back(sum(s, A[i]));
            add(s, A[i] + 1, 1);
        }
        return ans;
    }
private:
    static const int N = 10001;
   
    int lowbit(int x) {
        return x & -x;
    }
   
    int sum(vector<int> &a, int i) {
        int sum = 0;
        while (i > 0) {
            sum += a[i];
            i -= lowbit(i);
        }
        return sum;
    }
   
    void add(vector<int> &a, int i, int val) {
        if (i == 0) {
            return;
        }
        while (i <= N) {
            a[i] += val;
            i += lowbit(i);
        }
    }
};
