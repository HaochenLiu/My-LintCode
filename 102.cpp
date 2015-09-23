/*
102. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Have you met this question in a real interview?
Example
Given -21->10->4->5, tail connects to node index 1, return true
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
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};
