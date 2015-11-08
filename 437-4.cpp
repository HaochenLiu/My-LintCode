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

// Time:  O(nk)
// Space: O(n)

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        int n = pages.size();
        if(k == 0) return 0;
        if(n == 0) return 0;
        if(n == 1) return pages[0];
        k = min(n, k);
        vector<int> sum_from_start(n, 0);
        partial_sum(pages.begin(), pages.end(), sum_from_start.begin());
        vector<vector<int> > minutes(2, vector<int>(n, INT_MAX));
        for (int j = 0; j < n; j++) {
            minutes[1][j] = sum_from_start[j];
        }
        for (int i = 2; i <= k; i++) {
            minutes[i % 2][0] = sum_from_start[0];
            int left = 0, right = 1;
            while (right < n) {
                int curr = sum_from_start[right] - sum_from_start[left];
                minutes[i % 2][right] = min(minutes[i % 2][right], max(curr, minutes[(i - 1) % 2][left]));
                if (left < right && minutes[(i - 1) % 2][left] < curr) {
                    left++;
                } else {
                    right++;
                    // note: we should calculate the next solution starting from left - 1
                    if (left > 0) {
                        left--;
                    }
                }
            }
        }
        return minutes[k % 2][n - 1];
    }
};
