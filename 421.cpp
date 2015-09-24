/*
421. Simplify Path

Given an absolute path for a file (Unix-style), simplify it.
Have you met this question in a real interview?
Example
"/home/", => "/home"
"/a/./b/../../c/", => "/c"
Challenge
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    /**
     * @param path the original path
     * @return the simplified path
     */
    string simplifyPath(string& path) {
        // Write your code here
        stack<string> s;
        string str;
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                if(str == "..") {
                    if(!s.empty()) {
                        s.pop();
                    }
                } else if (str != "." && str != "") {
                    s.push(str);
                }
                str = "";
            } else {
                str += path[i];
            }
        }
        
        if(str == "..") {
            if (!s.empty()) {
                s.pop();
            }
        } else if (str != "." && str != "") {
            s.push(str);
        }
        
        if(s.empty()) {
            return "/";
        }
        
        string ret;
        while(!s.empty()) {
            ret = "/" + s.top() + ret;
            s.pop();
        }
        
        return ret;
    }
};
