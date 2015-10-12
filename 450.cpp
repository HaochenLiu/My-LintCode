/*
450. Reverse Nodes in k-Group

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed. Only constant memory is allowed.

Have you met this question in a real interview? Yes
Example
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5
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
private:
    int getCnt(ListNode* node) {
        int res = 0;
        while(node) {
            node = node->next;
            res++;
        }

        return res;
    }
public:
    /**
     * @param head a ListNode
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        if(head == NULL || head->next == NULL) return head;
        if(k <= 1) return head;
        int len = getCnt(head);
        if(k > len) return head;
        int times = len / k;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        for(int i = 0; i < times; i++) {
            for(int j = 0; j < k - 1; j++) {
                ListNode* move = cur->next;
                cur->next = move->next;
                move->next = ins->next;
                ins->next = move;
            }
            ins = cur;
            cur = cur->next;
        }

        return dummy.next;
    }
};
