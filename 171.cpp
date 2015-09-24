/*
171. Anagrams

Given an array of strings, return all groups of strings that are anagrams.
Have you met this question in a real interview?
Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].
Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].
Note
All inputs will be in lower-case
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        int n = strs.size();
        vector<string> res;
        if(n == 0) return res;
        unordered_map<string, int> m;
        for(int i = 0; i < n; i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()) {
                m[s] = i;
            } else {
                if(m[s] != -1) {
                    res.push_back(strs[m[s]]);
                    m[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        
        return res;
    }
};
