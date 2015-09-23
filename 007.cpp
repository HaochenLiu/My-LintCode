/*
007. Binary Tree Serialization

Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
There is no limit of how you deserialize or serialize a binary tree, you only need to make sure you can serialize a binary tree to a string and deserialize this string to the original structure.
Have you met this question in a real interview?
Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:
 3
 / \
9  20
  /  \
 15   7


Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.
You can use other method to do serializaiton and deserialization.
*/

#include <vector>
using namespace std;
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
 */
class Solution {
public:
    string serialize(TreeNode *root) {
        vector<string> v;
        serializePreorder(root, v);
        string ans = "";
        int n = v.size();
        for (int i = 0; i < n; ++i) {
            ans += v[i];
            ans.push_back(' ');
        }
        ans.pop_back();

        return ans;
    }

    TreeNode *deserialize(string data) {
        int n = data.length();
        int i = 0;
        int j = 0;
        vector<string> v;
        
        while (i < n) {
            string s = "";
            while (i < n && data[i] != ' ') {
                s.push_back(data[i++]);
            }
            v.push_back(s);
            i++;
        }
        
        TreeNode *root;
        int idx = 0;
        deserializePreorder(root, v, idx);

        return root;
    }
private:
    void serializePreorder(TreeNode* root, vector<string>& v) {
        if (root == NULL) {
            v.push_back("#");
            return;
        }
        v.push_back(to_string(root->val));
        serializePreorder(root->left, v);
        serializePreorder(root->right, v);
    }
    
    void deserializePreorder(TreeNode*& root, vector<string>& v, int& idx) {
        if (v[idx] == "#") {
            root = NULL;
            ++idx;
        } else {
            root = new TreeNode(atoi(v[idx].data()));
            ++idx;
            deserializePreorder(root->left, v, idx);
            deserializePreorder(root->right, v, idx);
        }
    }
};
