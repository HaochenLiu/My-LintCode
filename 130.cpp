/*
130. Heapify

Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
Have you met this question in a real interview?
Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.
Challenge
O(n) time complexity
Clarification
What is heap?
Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

What is heapify?
Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

What if there is a lot of solutions?
Return any of them.
Given an integer array, heapify it into a min-heap array.
For a heap array A, A[0] is the root of heap, and for each A[i], A[i * 2 + 1] is the left child of A[i] and A[i * 2 + 2] is the right child of A[i].
Have you met this question in a real interview?
Example
Given [3,2,1,4,5], return [1,2,3,4,5] or any legal heap array.
Challenge
O(n) time complexity
Clarification
What is heap?
Heap is a data structure, which usually have three methods: push, pop and top. where "push" add a new element the heap, "pop" delete the minimum/maximum element in the heap, "top" return the minimum/maximum element.

What is heapify?
Convert an unordered integer array into a heap array. If it is min-heap, for each element A[i], we will get A[i * 2 + 1] >= A[i] and A[i * 2 + 2] >= A[i].

What if there is a lot of solutions?
Return any of them.
*/

/*
Time: O(n)
级数求和
*/

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n = A.size();
        int i = 0;
        int j = 0;
        int minIdx = 0;
        int minVal = INT_MAX;
        for(int i = (n - 1) / 2; i >= 0; i--) {
            j = i;
            while(2 * j  + 1 < n) {
                minIdx = j;
                minVal = A[j];
                if(A[2 * j + 1] < minVal) {
                    minIdx = 2 * j + 1;
                    minVal = A[minIdx];
                }
                if(2 * j + 2 < n && A[2 * j + 2] < minVal) {
                    minIdx = 2 * j + 2;
                    minVal = A[minIdx];
                }
                if(minIdx == j) {
                    break;
                }
                swap(A[j], A[minIdx]);
                j = minIdx;
            }
        }
    }
};
