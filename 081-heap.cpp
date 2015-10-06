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

#include <queue>
using namespace std;

class HHeapMin {
public:
    int A[5001];
    int size;

    HHeapMin() {
        memset(A, 0, sizeof(A));
        size = 0;
    }

    void push(int n) {
        A[size] = n;
        size++;
        int i = size - 1;
        while(i > 0) {
            int j = (i - 1) / 2;
            if(A[j] > A[i]) {
                swap(A[j], A[i]);
                i = j;
            } else {
                break;
            }
        }
        return;
    }
    
    int top() {
        return A[0];
    }
    
    void pop() {
        A[0] = A[size - 1];
        size--;
        int i = 0;
        while(2 * i + 1 < size) {
            int minIdx = i;
            if(A[2 * i + 1] < A[minIdx]) {
                minIdx = 2 * i + 1;
            }
            if(2 * i + 2 < size && A[2 * i + 2] < A[minIdx]) {
                minIdx = 2 * i + 2;
            }
            if(minIdx == i) {
                break;
            }
            swap(A[i], A[minIdx]);
            i = minIdx;
        }
        return;
    }
};

class HHeapMax {
public:
    int A[5001];
    int size;

    HHeapMax() {
        memset(A, 0, sizeof(A));
        size = 0;
    }

    void push(int n) {
        A[size] = n;
        size++;
        int i = size - 1;
        while(i > 0) {
            int j = (i - 1) / 2;
            if(A[j] < A[i]) {
                swap(A[j], A[i]);
                i = j;
            } else {
                break;
            }
        }
        return;
    }
    
    int top() {
        return A[0];
    }
    
    void pop() {
        A[0] = A[size - 1];
        size--;
        int i = 0;
        while(2 * i + 1 < size) {
            int maxIdx = i;
            if(A[2 * i + 1] > A[maxIdx]) {
                maxIdx = 2 * i + 1;
            }
            if(2 * i + 2 < size && A[2 * i + 2] > A[maxIdx]) {
                maxIdx = 2 * i + 2;
            }
            if(maxIdx == i) {
                break;
            }
            swap(A[i], A[maxIdx]);
            i = maxIdx;
        }
        return;
    }
};

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        int n = nums.size();
        HHeapMax small;
        HHeapMin large;
        vector<int> res;

        small.push(INT_MIN);
        large.push(INT_MAX);
        for(int i = 0; i < n; ++i) {
            if((i & 1) == 0) {
                small.push(nums[i]);
            } else {
                large.push(nums[i]);
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
