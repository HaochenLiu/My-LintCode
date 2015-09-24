/*
184. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.
Have you met this question in a real interview?
Example
Given [1, 20, 23, 4, 8], the largest formed number is 8423201.
Note
The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    string largestNumber(vector<int> &num) {
        // write your code here
        if(num.size() == 0) return "";
        string str = "";

        while(!num.empty()) {
                int idx1 = 0;
                for(int idx2 = 1; idx2 < num.size(); idx2++) {
                if(to_string(num[idx2]) + to_string(num[idx1]) > to_string(num[idx1]) + to_string(num[idx2])) {
                    idx1 = idx2;
                }
            }
            str += to_string(num[idx1]);
            num.erase(num.begin() + idx1);
        }
        while(str[0] == '0' && str.size() > 1) {
            str.erase(str.begin());
        }
        return str;
    }
};
