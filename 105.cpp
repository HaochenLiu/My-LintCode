/*
105. Copy List with Random Pointer

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
Have you met this question in a real interview?
Example
Challenge
Could you solve it with O(1) space?
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(head == NULL) return NULL;
        RandomListNode dummy(0);
        dummy.next = head;
        RandomListNode* ins = &dummy;
        RandomListNode* cur = ins->next;
        while(cur) {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        
        cur = ins->next;
        RandomListNode* node = cur->next;
        while(cur) {
            if(cur->random == NULL) {
                node->random = NULL;
            } else {
                node->random = cur->random->next;
            }
            cur = node->next;
            if(cur != NULL) {
                node = cur->next;
            }
        }

        cur = ins->next;
        node = cur->next;
        ins->next = node;
        while(cur) {
            cur->next = node->next;
            cur = cur->next;
            if(cur) {
                node->next = cur->next;
                node = node->next;
            }
        }
        
        return dummy.next;
    }
};
