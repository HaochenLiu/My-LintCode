/*
055. Compare Strings

Compare two strings A and B, determine whether A contains all of the characters in B.
The characters in string A and B are all Upper Case letters.
Have you met this question in a real interview?
Example
For A = "ABCD", B = "ACD", return true.
For A = "ABCD", B = "AABC", return false.
Note
The characters of B in A are not necessary continuous or ordered.
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        // write your code here
        int exist[256];
        memset(exist, 0, sizeof(exist));
        int m = A.size();
        int n = B.size();
        for(int i = 0; i < m; i++) {
            exist[A[i]]++;
        }

        for(int i = 0; i < n; i++) {
            exist[B[i]]--;
        }
        
        for(int i = 0; i < 256; i++) {
            if(exist[i] < 0) {
                return false;
            }
        }
        
        return true;
    }
};
