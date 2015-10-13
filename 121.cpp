/*
121. Word Ladder II

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
Have you met this question in a real interview?
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
 [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]


Note
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
private:
    void findDict2(unordered_map<string,vector<string>>& m, string str, unordered_set<string> &dict, unordered_set<string> &next_lev) {
        int sz = str.size();
        string s = str;
        for(int i = 0; i < sz; i++) {
            s = str;
            for(char j = 'a'; j <= 'z'; j++) {
                s[i] = j;
                if(dict.find(s) != dict.end()) {
                    next_lev.insert(s);
                    m[s].push_back(str);
                }
            }
        }
    }
    
    void output(unordered_map<string,vector<string>>& m, vector<vector<string>>& res, vector<string>& path, string &start, string last){
        if(last == start){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        } else {
            for(int i = 0; i < m[last].size(); i++){
                path.push_back(m[last][i]);
                output(m, res, path, start, m[last][i]);
                path.pop_back();
            }
        }
    }
    
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        // write your code here
        unordered_map<string,vector<string>> m;
        vector<vector<string>> res;
        vector<string> path;

        wordList.insert(beginWord);
        wordList.insert(endWord);
        
        unordered_set<string> cur_lev;
        cur_lev.insert(beginWord);
        unordered_set<string> next_lev;
        path.push_back(endWord);
        
        while(true) {
            for(auto it = cur_lev.begin(); it != cur_lev.end(); it++) {
                wordList.erase(*it);
            }

            for(auto it = cur_lev.begin(); it != cur_lev.end(); it++) {
                findDict2(m, *it, wordList, next_lev);
            }

            if(next_lev.empty()) {
                return res;
            }
            
            if(next_lev.find(endWord) != wordList.end()) {
                output(m, res, path, beginWord, endWord);
                return res;
            }

            cur_lev.clear();
            cur_lev = next_lev;
            next_lev.clear();
        }
        return res;    
    }
};
