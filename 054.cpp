/*
054. String to Integer(atoi)

Implement function atoi to convert a string to an integer.
If no valid conversion could be performed, a zero value is returned.
If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
Have you met this question in a real interview?
Example
"10" => 10
"-1" => -1
"123123123123123" => 2147483647
"1.0" => 1
*/

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        // write your code here
        if(str.empty() || str[0] == '\0') return 0;
        
        int i = 0;
        while(isspace(str[i])) {
            i++;
        }

        int sign = 1;
        if(str[i] == '-') {
            sign = -1;
            i++;
        } else if(str[i] == '+') {
            i++;
        }
        
        long long res = 0;
        while(isdigit(str[i])) {
            res *= 10;
            res += (str[i] - '0');
            if(res > INT_MAX) {
                if(sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            i++;
        }
        
        if(sign == 1) {
            return res;
        } else {
            return -res;
        }
    }
};
