/*
511. Swap Two Nodes in Linked List Show result 

Given a linked list and two values v1 and v2. Swap the two nodes in the linked list with values v1 and v2. It's guaranteed there is no duplicate values in the linked list. If v1 or v2 does not exist in the given linked list, do nothing.

Have you met this question in a real interview? Yes
 Notice

You should swap the two nodes with values v1 and v2. Do not directly swap the values of the two nodes.

Example
Tags
Related Problems
 Notes
Given 1->2->3->4->null and v1 = 2, v2 = 4.

Return 1->4->3->2->null.
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
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    ListNode* swapNodes(ListNode* head, int v1, int v2) {
        // Write your code here
        if(head == NULL || head->next == NULL) return head;
        if(v1 == v2) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        ListNode* node1 = NULL;
        ListNode* node2 = NULL;

        while(ins->next) {
            if(ins->next->val == v1) {
                node1 = ins;
            }
            else if(ins->next->val == v2) {
                node2 = ins;
            }
            
            if(node1 && node2) {
                break;
            }
            ins = ins->next;
        }
        
        if(node1 == NULL || node2 == NULL) {
            return head;
        }
        
        if(node2 == node1->next) {
            ListNode* move = node2->next;
            node2->next = move->next;
            move->next = node1->next;
            node1->next = move;
        } else if(node1 == node2->next) {
            ListNode* move = node1->next;
            node1->next = move->next;
            move->next = node2->next;
            node2->next = move;
        } else {
            ListNode* move = node2->next;
            node2->next = move->next;
            move->next = node1->next;
            node1->next = move;

            node1 = node1->next;

            move = node1->next;
            node1->next = move->next;
            move->next = node2->next;
            node2->next = move;
        } 
        
        return dummy.next;
    }
};
