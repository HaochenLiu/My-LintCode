/*
212. Space Replacement

Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.
Have you met this question in a real interview?
Example
Given "Mr John Smith", length = 13.
The string after replacement should be "Mr%20John%20Smith".
Note
If you are using Java or Python，please use characters array instead of string.
Challenge
Do it in-place.
*/

class Solution {
public:
    /**
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char string[], int length) {
        // Write your code here
        int cnt = 0;
        for(int i = 0; i < length; i++) {
            if(isspace(string[i])) {
                cnt++;
            }
        }

        int res = length + 2 * cnt;
        int idx1 = length - 1;
        int idx2 = res - 1;
        
        for(int i = idx1; i >= 0; i--) {
            if(cnt == 0) {
                break;
            }

            if(!isspace(string[i])) {
                string[idx2] = string[idx1];
                idx2--;
                idx1--;
            } else {
                string[idx2--] = '0';
                string[idx2--] = '2';
                string[idx2--] = '%';
                idx1--;
                cnt--;
            }
        }
        
        return res;
    }
};  
