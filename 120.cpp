/*
120. Word Ladder

Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:
Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
Have you met this question in a real interview?
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Note
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // write your code here
        if (start.size() != end.size()) return 0;
        if (start.empty() || end.empty()) return 1;
        if (dict.size() == 0) return 0;

        int distance = 1;
        queue<string> queToPush, queToPop;
        queToPop.push(start);
        while (dict.size() > 0 && !queToPop.empty()) {
            while (!queToPop.empty()) {
                string str(queToPop.front());
                queToPop.pop();
                for (int i = 0; i < str.size(); i++) {
                    for (char j = 'a'; j <= 'z'; j++) {
                        if (j == str[i]) {
                            continue;
                        }
                        char temp = str[i];
                        str[i] = j;
                        if (str == end) return distance + 1;
                        if (dict.count(str) > 0) {
                            queToPush.push(str);
                            dict.erase(str);
                        }
                        str[i] = temp;
                    }
                }
            }
            swap(queToPush, queToPop);
            distance++;
        }
        return 0;
    }
};
