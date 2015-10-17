/*
223. Palindrome Linked List

Implement a function to check if a linked list is a palindrome.

Have you met this question in a real interview? Yes
Example
Given 1->2->1, return true

Challenge
Could you do it in O(n) time and O(1) space?
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
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* ins = &dummy;
        ListNode* cur = ins->next;
        while(cur->next) {
            ListNode* move = cur->next;
            cur->next = move->next;
            move->next = ins->next;
            ins->next = move;
        }
        
        return dummy.next;
    }
       
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(head == NULL || head->next == NULL) return true;
        int cnt = getCnt(head);
        ListNode* cur = head;

        for(int i = 0; i < (cnt - 1) / 2; i++) {
            cur = cur->next;
        }
        
        ListNode* mid = reverseList(cur->next);
        while(mid) {
            if(mid->val != head->val) {
                return false;
            }
            mid = mid->next;
            head = head->next;
        }
        return true;        
    }
};
