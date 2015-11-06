/*
Convert Binary Search Tree to Doubly Linked List

Convert a binary search tree to doubly linked list with in-order traversal.

Have you met this question in a real interview? Yes
Example
Given a binary search tree:

    4
   / \
  2   5
 / \
1   3
return 1<->2<->3<->4<->5
*/

/**
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        // Write your code here
        if(root == NULL) return NULL;
        stack<TreeNode*> st;
        TreeNode* node = root;
        DoublyListNode dummy(0);
        DoublyListNode* tail = &dummy;

        while(!st.empty() || node) {
            if(node) {
                while(node) {
                    st.push(node);
                    node = node->left;
                }
            } else {
                node = st.top();
                st.pop();
                tail->next = new DoublyListNode(node->val);
                tail->next->prev = tail;
                tail = tail->next;
                node = node->right;
            }
        }
        
        return dummy.next;
    }
};
