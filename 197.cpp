/*
197. Permutation Index

Given a permutation which contains no repeated number, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.
Have you met this question in a real interview?
Example
Given [1,2,4], return 1.
*/

// Time:  O(n^2)
// Space: O(1)

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        long long index = 1;
        int position = 2;
        long long factor = 1;
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            int successors = 0;
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successors;
                }
            }
            index += successors * factor;
            factor *= position;
            ++position;
        }
        return index;
    }
};
