/*
204. Singleton

Singleton is a most widely used design pattern. If a class has and only has one instance at every moment, we call this design as singleton. For example, for class Mouse (not a animal mouse), we should design it in singleton.
You job is to implement a getInstance method for given class, return the same instance of this class every time you call this method.
Have you met this question in a real interview?
Example
In Java:
A a = A.getInstance();
A b = A.getInstance();


a should equal to b.
Challenge
If we call getInstance concurrently, can you make sure your code could run correctly?
*/

// Time:  O(1)
// Space: O(1)

// Thread-Safe, Lazy Initilization
class Solution {
public:
    /**
     * @return: The same instance of this class every time
     */
    static Solution* getInstance() {
        // C++ 11 thread-safe local-static-initialization.
        static Solution *instance = new Solution();

        return instance;
    }

    // Noncopyable.
    Solution(const Solution&) = delete;
    Solution& operator=(const Solution&) = delete;

private:
    Solution() {}
    ~Solution() {}
};
