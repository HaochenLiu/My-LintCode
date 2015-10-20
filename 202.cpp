/*
202. Segment Tree Query

For an integer array (index from 0 to n-1, where n is the size of this array), in the corresponding SegmentTree, each node stores an extra attribute max to denote the maximum number in the interval of the array (index from start to end).
Design a query method with three parameters root, start and end, find the maximum number in the interval [start, end] by the given root of segment tree.
Have you met this question in a real interview?
Example
For array [1, 4, 2, 3], the corresponding Segment Tree is:
                 [0, 3, max=4]
                 /             \
          [0,1,max=4]        [2,3,max=3]
          /         \        /         \
   [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]


query(root, 1, 1), return 4
query(root, 1, 2), return 4
query(root, 2, 3), return 3
query(root, 0, 2), return 4
Note
It is much easier to understand this problem if you finished Segment Tree Build first.
*/

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode* root, int start, int end) {
        // write your code here
        if(root == NULL) return 0;
        if(start > end) return 0;
        if(start == root->start && end == root->end) return root->max;
        int t1 = query(root->left, start, min(end, root->left->end));
        int t2 = query(root->right, max(start, root->right->start), end);
        return max(t1, t2);
    }
};
