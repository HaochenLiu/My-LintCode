/*
006. Merge Sorted Array II

Merge two given sorted integer array A and B into a new sorted integer array.
Have you met this question in a real interview?
Example
A=[1,2,3,4]
B=[2,4,5,6]
return [1,2,2,3,4,4,5,6]
Challenge
How can you optimize your algorithm if one array is very large and the other is very small?
*/

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        if(A.size() == 0) return B;
        if(B.size() == 0) return A;

        int m = A.size();
        int n = B.size();
        vector<int> res(m + n, 0);
        int i = 0;
        int j = 0;
        while(i < m || j < n) {
            if(i == m) {
                for(int k = j; k < n; k++) {
                    res[i + k] = B[k];
                }
                break;
            }
            if(j == n) {
                for(int k = i; k < m; k++) {
                    res[k + j] = A[k];
                }
                break;
            }
            if(A[i] < B[j]) {
                res[i + j] = A[i];
                i++;
            } else {
                res[i + j] = B[j];
                j++;
            }
        }

        return res;
    }
};
