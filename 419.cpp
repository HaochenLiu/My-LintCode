/*
419. Roman to Integer

Given a roman numeral, convert it to an integer.
The answer is guaranteed to be within the range from 1 to 3999.
Have you met this question in a real interview?
Example
IV -> 4
XII -> 12
XXI -> 21
XCIX -> 99
Clarification
What is Roman Numeral?
https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
http://baike.baidu.com/view/42061.htm
*/

class Solution {
public:
    /**
     * @param s Roman representation
     * @return an integer
     */
    int romanToInt(string& s) {
        // Write your code here
        int n = s.length();
        int id = 0;
        int res = 0;

        while(s[id] == 'M') {
            res += 1000;
            id++;
        }

        if(s.substr(id, 2) == "CM") {
            res += 900;
            id += 2;
        }

        if(s.substr(id, 2) == "CD") {
            res += 400;
            id += 2;
        }

        if(s[id] == 'D') {
            res += 500;
            id++;
        }

        while(s[id] == 'C') {
            res += 100;
            id++;
        }

        if(s.substr(id, 2) == "XC") {
            res += 90;
            id += 2;
        }

        if(s.substr(id, 2) == "XL") {
            res += 40;
            id += 2;
        }

        if(s[id] == 'L') {
            res += 50;
            id++;
        }

        while(s[id] == 'X') {
            res += 10;
            id++;
        }

        if(s.substr(id, 2) == "IX") {
            res += 9;
            id += 2;
        }

        if(s.substr(id, 2) == "IV") {
            res += 4;
            id += 2;
        }

        if(s[id] == 'V') {
            res += 5;
            id++;
        }

        while(s[id] == 'I') {
            res += 1;
            id++;
        }

        return res;
    }
};
