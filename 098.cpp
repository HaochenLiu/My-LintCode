/*
098. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
Have you met this question in a real interview?
Example Given 1-3->2->null, sort it to 1->2->3->null.
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
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* head = &dummy;
        ListNode* cur = head;
        while(l1 || l2) {
            if(!l1) {
                cur->next = l2;
                break;
            }
            
            if(!l2) {
                cur->next = l1;
                break;
            }
            
            if(l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return head->next;
    }
    
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next && fast->next->next) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        
        return mergeTwoLists(l1, l2);
    }
};
