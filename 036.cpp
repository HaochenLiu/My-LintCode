/*
036. Reverse Linked List II

Reverse a linked list from position m to n.
Have you met this question in a real interview?
Example
Given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.
Note
Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.
Challenge
Reverse it in-place and in one-pass
*/

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(head == NULL || head->next == NULL || m == n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        
        for(int i = 0; i < m - 1; i++) {
            ins = ins->next;
        }
        
        ListNode* cur = ins->next;
        for(int i = 0; i < n - m; i++) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }
        
        return dummy.next;
    }
};
