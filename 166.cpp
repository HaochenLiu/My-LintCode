/*
166. Nth to Last Node in List

Find the nth to last element of a singly linked list. 
The minimum number of nodes in list is n.
Have you met this question in a real interview?
Example
Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
*/

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
class Solution {
private:
    int getCnt(ListNode* node) {
        int res = 0;
        while(node) {
            node = node->next;
            res++;
        }

        return res;
    }

public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        int cnt = getCnt(head);
        if(cnt < n) return 0;
        for(int i = 0; i < cnt - n; i++) {
            head = head->next;
        }
        return head;
    }
};
