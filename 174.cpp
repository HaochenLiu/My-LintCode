/*
174. Remove Nth Node From End of List

Given a linked list, remove the nth node from the end of list and return its head.
Have you met this question in a real interview?
Example
Given linked list: 1->2->3->4->5->null, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5->null.
Note
The minimum number of nodes in list is n.
Challenge
O(n) time
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
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = &dummy;
        for(int i = 0; i < n; i++) {
            cur = cur->next;
        }
        while(cur->next) {
            ins = ins->next;;
            cur = cur->next;;
        }
        
        ListNode* del = ins->next;
        ins->next = del->next;;
        delete(del);
        
        return dummy.next;
    }
};
