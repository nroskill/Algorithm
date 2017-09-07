/**
 * https://leetcode.com/problems/invert-binary-tree/
 * By Nroskill
 * runtime 3 ms
 * language cpp
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void invert(TreeNode* root) {
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left)
            invert(root->left);
        if(root->right)
            invert(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root)
            invert(root);
        return root;
    }
};