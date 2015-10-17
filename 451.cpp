/*
451. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.

Have you met this question in a real interview? Yes
Example
Given 1->2->3->4, you should return the list as 2->1->4->3.

Challenge
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        while(cur && cur->next) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
            ins = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
