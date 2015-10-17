/*
452. Remove Linked List Elements

Remove all elements from a linked list of integers that have value val.

Have you met this question in a real interview? Yes
Example
Given 1->2->3->3->4->5->3, val = 3, you should return the list as 1->2->4->5
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
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* cur = &dummy;
        ListNode* tmp = cur->next;

        while(cur->next) {
            if(tmp->val != val) {
                cur = cur->next;
                tmp = cur->next;
            } else {
                ListNode* del = cur->next;
                delete(del);
                cur->next = cur->next->next;
                tmp = cur->next;
            }
        }

        return dummy.next;
    }
};
