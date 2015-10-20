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
    stack<int> s;
    stack<int> minInt;
    
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        s.push(number);
        if(minInt.empty() || number <= minInt.top()) {
            minInt.push(number);
        }

        return;
    }
    
    int pop() {
        // write your code here
        int res = s.top();
        if(minInt.top() == s.top()) {
            minInt.pop();
        }
        s.pop();

        return res;
    }

    int min() {
        // write your code here
        return minInt.top();
    }
};
