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

// Time:  O(nlogp), p is total pages.
// Space: O(1)

class Solution {
public:
    /**
     * @param pages: a vector of integers
     * @param k: an integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        if (k >= pages.size()) {
            return *max_element(pages.cbegin(), pages.cend());
        }

        int sum = 0;
        for (const auto& page : pages) {
            sum += page;
        }
        int average = sum / k;   // Lower bound.
        return binarySearch(pages, k, average, sum);
    }

    int binarySearch(const vector<int> &pages,
                     const int k, int left, int right) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (valid(pages, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    // Check whether everyone copying at most x pages works or not.
    bool valid(const vector<int> &pages, const int k, const int x) {
        int sum = 0;
        int people = 0;
        for (int i = 0; i < pages.size() && people < k; ++i) {
            if (sum + pages[i] > x) {
                sum = 0;
                ++people;
            }
            sum += pages[i];
        }
        return  people < k && sum <= x;
    }
};
