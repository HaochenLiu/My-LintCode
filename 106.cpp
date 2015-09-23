/*
106. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
Have you met this question in a real interview?
Example
              2
1->2->3  =>   / \
             1   3
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
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
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

    TreeNode* sortedListToBSTRecur(ListNode*& head, int beg, int end) {
        if(beg > end) return NULL;
        int mid = beg + (end - beg) / 2;
        TreeNode* leftNode = sortedListToBSTRecur(head, beg, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftNode;
        head = head->next;
        root->right = sortedListToBSTRecur(head, mid + 1, end);
        return root;
    }
    
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        if(head == NULL) return NULL;
        int cnt = getCnt(head);
        return sortedListToBSTRecur(head, 0, cnt - 1);
    }
};
