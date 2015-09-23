/*
012. Min Stack

Implement a stack with min() function, which will return the smallest number in the stack.
It should support push, pop and min operation all in O(1) cost.
Have you met this question in a real interview?
Example
Operations: push(1), pop(), push(2), push(3), min(), push(1), min() Return: 1, 2, 1
Note
min operation will never be called if there is no number in the stack
*/

class MinStack {
private:
    vector<int> v;
    
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        v.push_back(number);
    }

    int pop() {
        // write your code here
        int res = v[v.size() - 1];
        v.pop_back();
        return res;
    }

    int min() {
        // write your code here
        if(v.size() == 0) return 0;
        int minVal = v[0];
        for(int i = 1; i < v.size(); i++) {
            if(v[i] < minVal) {
                minVal = v[i];
            }
        }

        return minVal;
    }
};
