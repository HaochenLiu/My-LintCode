/*
198. Permutation Index II

Given a permutation which may contain repeated numbers, find its index in all the permutations of these numbers, which are ordered in lexicographical order. The index begins at 1.
*/

// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        int position = 2;
        long long factor = 1;
        map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            ++number_to_count[A[i]];
            for (const auto& kvp : number_to_count) {
                if (kvp.first >= A[i]) {
                    break;
                }
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};
