/*
112. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.
Have you met this question in a real interview?
Example
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return head;
        ListNode* ins = head;
        ListNode* cur = ins->next;
        while(cur) {
            if(ins->val == cur->val) {
                ListNode* move = cur->next;
                ins->next = move;
                delete(cur);
                cur = move;
            } else {
                cur = cur->next;
                ins = ins->next;
            }
        }
        
        return head;
    }
};
