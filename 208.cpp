/*
208. Assignment Operator Overloading (C++ Only)

Implement an assignment operator overloading method.
Make sure that:
The new data can be copied correctly
The old data can be deleted / free correctly.
We can assign like A = B = C
Have you met this question in a real interview?
Example
If we assign like A = B, the data in A should be deleted, and A can have a copy of data from B. If we assign like A = B = C, both A and B should have a copy of data from C.
Challenge
Consider about the safety issue if you can and make sure you released the old data.
Clarification
This problem is for C++ only as Java and Python don't have overloading for assignment operator.
*/

#include <cstring>
using namespace std;

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    
    Solution(char *pData) {
        this->m_pData = pData;
    }
    
    ~Solution() {
        delete m_pData;
        m_pData = NULL;
    }

    // Implement an assignment operator
    Solution &operator = (const Solution &object) {
        if (m_pData == object.m_pData) {
            // No need to clone yourself
            return *this;
        }

        if (m_pData != NULL) {
            delete[] m_pData;
            m_pData = NULL;
        }
        char *ptr = NULL;
        if (object.m_pData != NULL) {
                        int len = strlen(object.m_pData);
            m_pData = new char[len + 1];
            strcpy(m_pData, object.m_pData);
        }
        return *this;
    }
};
