/*
133. Longest Words

Given a dictionary, find all of the longest words in the dictionary.
Have you met this question in a real interview?
Example
Given
{
  "dog",
  "google",
  "facebook",
  "internationalization",
  "blabla"
}


the longest words are(is) ["internationalization"].
Given
{
  "like",
  "love",
  "hate",
  "yes"
}


the longest words are ["like", "love", "hate"].
Challenge
It's easy to solve it in two passes, can you do it in one pass?
*/

#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        int i;
        int len = 0;
        vector<string> ans;
        
        for (i = 0; i < dictionary.size(); ++i) {
            len = max(len, (int)dictionary[i].length());
        }
        for (i = 0; i < dictionary.size(); ++i) {
            if (len == dictionary[i].length()) {
                ans.push_back(dictionary[i]);
            }
        }
        return ans;
    }
};
