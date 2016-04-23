/*
532. Reverse Pairs

For an array A, if i < j, and A [i] > A [j], called (A [i], A [j]) is a reverse pair.
return total of reverse pairs in A.

Have you met this question in a real interview? Yes
Example
Given A = [2, 4, 1, 3, 5] , (2, 1), (4, 1), (4, 3) are reverse pairs. return 3
*/

// An AVL tree node
class AVLTreeNode {
public:
    int val;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int height;
    int count;
    int leftSize;

    AVLTreeNode(int v) {
        val = v;
        left = NULL;
        right = NULL;
        height = 1; // new node is initially added at leaf
        count = 1;
        leftSize = 0;
    }
};

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(AVLTreeNode* node) {
    if(node == NULL) return 0;
    return node->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b)? a : b;
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
AVLTreeNode* rightRotate(AVLTreeNode* y) {
    AVLTreeNode* x = y->left;
    AVLTreeNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Update leftSize
    y->leftSize -= x->leftSize + x->count;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
AVLTreeNode* leftRotate(AVLTreeNode* x) {
    AVLTreeNode* y = x->right;
    AVLTreeNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Update leftSize
    y->leftSize += x->leftSize + x->count;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(AVLTreeNode* node) {
    if(node == NULL) return 0;
    return height(node->left) - height(node->right);
}

AVLTreeNode* insert(AVLTreeNode* node, int val) {
    /* 1. Perform the normal BST rotation */
    if(node == NULL) return (new AVLTreeNode(val));

    // If val already exists in BST, icnrement count and return
    if(val == node->val) {
        (node->count)++;
        return node;
    }

    /* Otherwise, recur down the tree */
    if(val < node->val) {
        node->left = insert(node->left, val);
        node->leftSize++;
    } else {
        node->right = insert(node->right, val);
    }

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
    this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if(balance > 1 && val < node->left->val) {
        return rightRotate(node);
    }

    // Right Right Case
    if(balance < -1 && val > node->right->val) {
        return leftRotate(node);
    }

    // Left Right Case
    if(balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if(balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
val value found in that tree. Note that the entire tree does not
need to be searched. */
AVLTreeNode* minValueNode(AVLTreeNode* node) {
    AVLTreeNode* current = node;

    /* loop down to find the leftmost leaf */
    while(current->left != NULL) {
        current = current->left;
    }

    return current;
}

AVLTreeNode* deleteNode(AVLTreeNode* root, int val) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if(root == NULL) return root;

    if(val < root->val) {
        // If the val to be deleted is smaller than the root's val,
        // then it lies in left subtree
        root->left = deleteNode(root->left, val);
        root->leftSize--;
    } else if(val > root->val) {
        // If the val to be deleted is greater than the root's val,
        // then it lies in right subtree
        root->right = deleteNode(root->right, val);
    } else {
        // if val is same as root's val, then This is the node
        // to be deleted
        if(root->count > 1) {
            // If val is present more than once, simply decrement
            // count and return
            (root->count)--;
            return root;
        }
        // ElSE, delete the node

        // node with only one child or no child
        if((root->left == NULL) || (root->right == NULL)) {
            AVLTreeNode* temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                temp->leftSize = root->leftSize;
                // One child case
                *root = *temp; // Copy the contents of the non-empty child
            }

            delete(temp);
        } else {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            AVLTreeNode* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
    }

    // If the tree had only one node then return
    if(root == NULL)
    return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = max(height(root->left), height(root->right)) + 1;

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to check whether
    // this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if(balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    // Left Right Case
    if(balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if(balance < -1 && getBalance(root->right) <= 0) {        
        return leftRotate(root);
    }

    // Right Left Case
    if(balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int searchSmaller(AVLTreeNode* root, int v) {
    AVLTreeNode* node = root;
    int res = 0;
    while(node) {
        if(node->val >= v) {
            node = node->left;
        } else {
            res += node->leftSize + node->count;
            node = node->right;
        }
    }
    return res;
}

class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        // Write your code here
        if(A.empty()) return 0;
        int n = A.size();
        long long res = 0;
        AVLTreeNode* root = new AVLTreeNode(A[n - 1]);
        for (int i = n - 2; i >= 1; i--) {
            res += searchSmaller(root, A[i]);
            root = insert(root, A[i]);
        }
        res += searchSmaller(root, A[0]);

        return res;
    }
};
