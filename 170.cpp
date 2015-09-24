/*
170. Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.
Have you met this question in a real interview?
Example
Given 1->2->3->4->5 and k = 2, return 4->5->1->2->3.
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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
        if(head == NULL || head->next == NULL || k < 1) return head;
        int cnt = getCnt(head);

        ListNode* node = head;
        ListNode* tail = head;
        while(node != NULL){
            tail = node;
            node = node->next;
        }
        
        k %= cnt;
        if(k == 0) return head;
        
        int left = cnt - k;
        node = head;
        for(int i = 0; i < left - 1; ++i) {
            node = node->next;
        }

        ListNode* newTail = node;
        ListNode* newHead = node->next;
        newTail->next = NULL;
        tail->next = head;
        return newHead;
    }
};
