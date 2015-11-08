/*
Copy Books II

Given n books( the page number of each book is the same) and an array of integer with size k means k people to copy the book and the i th integer is the time i th person to copy one book). You must distribute the continuous id books to one people to copy. (You can give book A[1],A[2] to one people, but you cannot give book A[1], A[3] to one people, because book A[1] and A[3] is not continuous.) Return the number of smallest minutes need to copy all the books.

Have you met this question in a real interview? Yes
Example
Given n = 4, array A = [3,2,4], .

Return 4( First person spends 3 minutes to copy book 1, Second person spends 4 minutes to copy book 2 and 3, Third person spends 4 minutes to copy book 4. )
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @param times: a vector of integers
     * @return: an integer
     */
    int copyBooksII(int n, vector<int> &times) {
        // write your code here
        if(times.empty() || n < 1) return 0;
        sort(times.begin(), times.end());
        int k = times.size();
        k = min(k, n);
        int left = times[0];
        int right = times[0] * n;
        while(left < right) {
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i = 0; i < k; i++) {
                cnt += mid / times[i];
            }
            if(cnt >= n) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
