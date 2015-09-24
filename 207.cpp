/*
207. Interval Sum II

Given an integer array in the construct method, implement two methods query(start, end) and modify(index, value):
For query(start, end), return the sum from index start to index end in the given array.
For modify(index, value), modify the number in the given index to value
Have you met this question in a real interview?
Example
Given array A = [1,2,7,8,5].
query(0, 2), return 10.
modify(0, 4), change A[0] from 1 to 4.
query(0, 1), return 6.
modify(2, 1), change A[2] from 7 to 1.
query(2, 4), return 14.
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.
Challenge
O(logN) time for query and modify.
*/

typedef long long int LL;
class Solution {
public:
    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) {
        n = A.size();
        a.resize(n + 1, 0);
        int i;
        for (i = 0; i < n; ++i) {
            add(i + 1, A[i]);
        }
    }
    
    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    LL query(int start, int end) {
        ++start;
        ++end;
        return sum(end) - sum(start - 1);
    }
    
    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        int oldValue = query(index, index);
        ++index;
        add(index, value - oldValue);
    }
private:
    vector<LL> a;
    int n;
    
    int lowbit(int x) {
        return x & -x;
    }
    
    void add(int index, int value) {
        while (index <= n) {
            a[index] += value;
            index += lowbit(index);
        }
    }
    
    LL sum(int index) {
        LL s = 0;
        while (index > 0) {
            s += a[index];
            index -= lowbit(index);
        }
        return s;
    }
};
