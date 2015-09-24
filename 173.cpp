/*
173. Insertion Sort List

Sort a linked list using insertion sort.
Have you met this question in a real interview?
Example
Given 1->3->2->0->null, return 0->1->2->3->null.
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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* prev = ins->next;
        ListNode* cur = prev->next;
        while(cur) {
            if(cur->val >= prev->val) {
                cur = cur->next;
                prev = prev->next;
            } else {
                ListNode* tmp = ins;
                while(true) {
                    if(tmp->next->val >= cur->val) {
                        ListNode* move = prev->next;
                        prev->next = cur->next;
                        cur->next = tmp->next;
                        tmp->next = move;
                        break;
                    }
                    tmp = tmp->next;
                }
                cur = prev->next;
            }
        }

        return dummy.next;
    }
};
