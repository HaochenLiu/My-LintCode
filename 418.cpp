/*
418. Integer to Roman

Given an integer, convert it to a roman numeral.
The number is guaranteed to be within the range from 1 to 3999.
Have you met this question in a real interview?
Example
4 -> IV
12 -> XII
21 -> XXI
99 -> XCIX
more examples at: http://literacy.kent.edu/Minigrants/Cinci/romanchart.htm
Clarification
What is Roman Numeral?
https://en.wikipedia.org/wiki/Roman_numerals
https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97
http://baike.baidu.com/view/42061.htm
*/

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int num) {
        // Write your code here
        string res;
        int num_of_M = num / 1000;
        res.append(num_of_M, 'M');
        num %= 1000;

        if(num / 100 == 9) {
            res.append("CM");
        } else if(num / 100 == 4) {
            res.append("CD");
        } else {
            int num_of_D = num / 500;
            res.append(num_of_D, 'D');
            num %= 500;

            int num_of_C = num / 100;
            res.append(num_of_C, 'C');
        }
        num %= 100;

        if(num / 10 == 9) {
            res.append("XC");
        } else if(num / 10 == 4) {
            res.append("XL");
        } else {
            int num_of_L = num / 50;
            res.append(num_of_L, 'L');
            num %= 50;

            int num_of_X = num / 10;
            res.append(num_of_X, 'X');
        }
        num %= 10;

        if(num == 9) {
            res.append("IX");
        } else if (num == 4) {
            res.append("IV");
        } else {
            int num_of_V = num / 5;
            res.append(num_of_V, 'V');

            num %= 5;
            res.append(num, 'I');
        }

        return res;
    }
};
