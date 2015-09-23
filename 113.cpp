/*
113. Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Have you met this question in a real interview?
Example
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        bool flag = false;
        int val = 0;
        while(ins->next) {
            ListNode* cur = ins->next;
            if(flag && cur->val == val) {
                ins->next = cur->next;
                delete(cur);
            } else {
                flag = false;
                if(ins->next->next == NULL) {
                    break;
                } else if(ins->next->val == ins->next->next->val) {
                    flag = true;
                    val = ins->next->val;
                    ListNode* cur = ins->next->next->next;
                    delete(ins->next->next);
                    delete(ins->next);
                    ins->next = cur;
                } else {
                    ins = ins->next;
                }
            }
        }
        
        return dummy.next;
    }
};
