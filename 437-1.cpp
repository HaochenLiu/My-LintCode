/*
437. Copy Books

Given an array A of integer with size of n( means n books and number of pages of each book) and k people to copy the book. You must distribute the continuous id books to one people to copy. (You can give book A[1],A[2] to one people, but you cannot give book A[1], A[3] to one people, because book A[1] and A[3] is not continuous.) Each person have can copy one page per minute. Return the number of smallest minutes need to copy all the books.
Have you met this question in a real interview?
Example
Given array A = [3,2,4], k = 2.
Return 5( First person spends 5 minutes to copy book 1 and book 2 and second person spends 4 minutes to copy book 3. )
Challenge
Could you do this in O(n*k) time ?
*/

// Time:  O(nk^2)
// Space: O(nk)

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        int n = pages.size();
        int dp[k + 1][n + 1];
        int sum = 0;
        int maxVal = 0;
        for(int i = 1; i <= n; i++){
            sum += pages[i - 1];
            dp[1][i] = sum;
            maxVal = max(maxVal, pages[i - 1]);
        }
        
        if(k >= n){
            return maxVal;
        }
        
        for(int i = 2; i <= k; i++){
            for(int j = n - 1; j >= i - 1; j--){
               int current = pages[j];
               int minVal = max(pages[j], dp[i - 1][j]);
               dp[i][j + 1] = minVal;
               for(int l = j - 1; l >= i - 1; l--){
                   current += pages[l];
                   int curMin = max(current, dp[i - 1][l]);
                   if(curMin < minVal){
                       dp[i][j + 1] = curMin;
                       minVal = curMin;
                   }
               }
            }
        }
        
        return dp[k][n];
    }
};
