/*
035. Reverse Linked List

Reverse a linked list.
Have you met this question in a real interview?
Example
For linked list 1->2->3, the reversed linked list is 3->2->1
Challenge
Reverse it in-place and in one-pass
*/

/**
 * Definition of ListNode
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        while(cur->next) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }
        
        return dummy.next;
    }
};
