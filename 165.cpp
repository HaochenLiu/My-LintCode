/*
165. Merge Two Sorted Lists

Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.
Have you met this question in a real interview?
Example
Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while(l1 || l2) {
            if(l1 == NULL) {
                cur->next = l2;
                break;
            }
            if(l2 == NULL) {
                cur->next = l1;
                break;
            }
            if(l1->val < l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }

        return dummy.next;
    }
};
