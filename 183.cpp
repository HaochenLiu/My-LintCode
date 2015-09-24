/*
183. Wood Cut

Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
Have you met this question in a real interview?
Example
For L=[232, 124, 456], k=7, return 114.
Note
You couldn't cut wood into float length.
Challenge
O(n log Len), where Len is the longest length of the wood.
*/

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int n = L.size();
        if(n == 0) return 0;
        int maxLen = L[0];
        int sum = 0;
        for(int i = 1; i < n; i++) {
            maxLen = max(maxLen, L[i]);
            sum += L[i];
        }
        if(sum < k) {
            return 0;
        }
        
        int left = 1;
        int right = maxLen;
        while(left < right) {
            int mid = left + (right - left);
            if(isValid(L, mid, k)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }

private:
    bool isValid(vector<int> L, int len, int k) {
        int res = 0;
        for(int i = 0; i < L.size(); i++) {
            res += (L[i] / len);
        }

        return (res >= k);
    }
};
