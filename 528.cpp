/*
528. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Have you met this question in a real interview? Yes
Example
Given the list [[1,1],2,[1,1]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].

Given the list [1,[4,[6]]], By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        it = nestedList.begin();
        end = nestedList.end();
    }

    int next() {
        auto res = myStack.top().getInteger();
        myStack.pop();
        return res;
    }

    bool hasNext() {
        while (myStack.empty() && it != end || !myStack.empty() && !myStack.top().isInteger()){
            if (myStack.empty()){
                myStack.push((*it));
                it++;
            }
            while (!myStack.empty() && !myStack.top().isInteger()){
                auto current = myStack.top().getList();
                myStack.pop();
                for (auto rit = current.rbegin(); rit!=current.rend();rit++){
                    myStack.push((*rit));
                }
            }
        }
        return !myStack.empty();
    }

private:
    stack<NestedInteger> myStack;
    vector<NestedInteger>::iterator it;
    vector<NestedInteger>::iterator end;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
