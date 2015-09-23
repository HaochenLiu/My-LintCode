/*
104. Merge k Sorted Lists

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.
Have you met this question in a real interview?
Example
Given lists:
[
  2->4->null,
  null,
  -1->null
],


return -1->2->4->null.
*/

#include <queue>
using namespace std;
/**
* Definition of ListNode
* class ListNode {
* public:
*     int val;
*     ListNode *next;
*     ListNode(int val) {
*         this->val = val;
*         this->next = NULL;
*     }
* }
*/
struct Comp {
    bool operator () (ListNode *&x, ListNode *&y)
    {
        return x->val > y->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Comp> pq;
        for (auto &it: lists) {
            if (it != NULL) {
                pq.push(it);
            }
        }
        ListNode *h, *t;
        ListNode *p, *q;
        
        h = t = NULL;
        while (!pq.empty()) {
            p = pq.top();
            q = p->next;
            pq.pop();
            if (q != NULL) {
                pq.push(q);
            }
            
            if (h != NULL) {
                t->next = p;
                t = t->next;
            } else {
                h = t = p;
            }
            t->next = NULL;
        }
        return h;
    }
};
