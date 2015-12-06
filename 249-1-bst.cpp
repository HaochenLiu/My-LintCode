/*
249. Count of Smaller Number before itself

Give you an integer array (index from 0 to n-1, where n is the size of this array, value from 0 to 10000) . For each element Ai in the array, count the number of element before this element Ai is smaller than it and return count number array.
Have you met this question in a real interview?
Example
For array [1,2,7,8,5], return [0,1,2,3,2]
Note
We suggest you finish problem Segment Tree Build, Segment Tree Query II and Count of Smaller Number before itself I first.
*/

class BSTNode {
public:
    BSTNode* left;
    BSTNode* right;
    int val;
    int leftSize;
    int selfSize;
    
    BSTNode(int v) {
        left = NULL;
        right = NULL;
        val = v;
        leftSize = 0;
        selfSize = 1;
    }
};

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int>& nums) {
        if(nums.empty()) return vector<int>{};
        int n = nums.size();
        vector<int> res(n, 0);
        BSTNode* root = new BSTNode(nums[0]);
        res[0] = 0;
        for (int i = 1; i < n; i++) {
            res[i] = searchSmaller(root, nums[i]);
            insert(root, nums[i]);
        }

        return res;
    }

private:
    int searchSmaller(BSTNode* root, int v) {
        BSTNode* node = root;
        int res = 0;
        while(node) {
            if(node->val >= v) {
                node = node->left;
            } else {
                res += node->leftSize + node->selfSize;
                node = node->right;
            }
        }
        return res;
    }

    void insert(BSTNode* root, int v) {
        BSTNode* node = root;
        int res = 0;
        while(true) {
            if(node->val == v) {
                node->selfSize++;
                break;
            } else if(node->val > v) {
                node->leftSize++;
                if(node->left != NULL) {
                    node = node->left;
                } else {
                    node->left = new BSTNode(v);
                    break;
                }
            } else {
                if(node->right != NULL) {
                    node = node->right;
                } else {
                    node->right = new BSTNode(v);
                    break;
                }
            }
        }
    }
};
