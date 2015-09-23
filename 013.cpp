/*
013. strStr

strstr (a.k.a find sub string), is a useful function in string operation. Your task is to implement this function.
For a given source string and a target string, you should output the first index(from 0) of target string in source string.
If target does not exist in source, just return -1.
Have you met this question in a real interview?
Example
If source = "source" and target = "target", return -1.
If source = "abcdabcdefg" and target = "bcd", return 1.
Challenge
O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)
Clarification
Do I need to implement KMP Algorithm in a real interview?
Not necessary. When you meet this problem in a real interview, the interviewer may just want to test your basic implementation ability. But make sure your confirm with the interviewer first.
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL) return -1;
        int n = strlen(source);
        int m = strlen(target);
        if(m == 0) return 0;
        vector<int> next(m, -1);
        getNext(next, target);
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            if(j == -1 || source[i] == target[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        
        if(j == m) {
            return (i - j);
        }
        return -1;
    }

    void getNext(vector<int>& next, const char *p) {
        // write your code here
        int m = strlen(p);
        int j = 0;
        int k = -1;
        while(j < m - 1) {
            if(k == -1 || p[j] == p[k]) {
                j++;
                k++;
                if(p[j] != p[k]) {
                    next[j] = k;
                } else {
                    next[j] = next[k];
                }
            } else {
                k = next[k];
            }
        }
    }
};
