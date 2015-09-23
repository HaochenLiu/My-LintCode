/*
049. Sort Letters by Case

Given a string which contains only letters. Sort it by lower case first and upper case second.
Have you met this question in a real interview?
Example
For "abAcD", a reasonable answer is "acbAD"
Note
It's not necessary to keep the original order of lower-case letters and upper case letters.
Challenge
Do it in one-pass and in-place.
*/

#include <cctype>
using namespace std;

class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        string &s = letters;
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (true) {
            while (i <= j && islower(s[i])) {
                ++i;
            }
            while (i <= j && isupper(s[j])) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(s[i++], s[j--]);
        }
    }
};
