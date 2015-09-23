/*
103. Linked List Cycle II

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Have you met this question in a real interview?
Example
Given -21->10->4->5, tail connects to node index 1，返回10
Challenge Follow up:
Can you solve it without using extra space?
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
     * @return: The node where the cycle begins.
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        
        if(fast == NULL || fast->next == NULL) {
            return NULL;
        }
        
        while(true) {
            if(head == slow) {
                break;
            }
            head = head->next;
            slow = slow->next;
            if(slow == NULL) {
                return NULL;
            }
        }
        
        return head;
    }
};
