/**
 * https://leetcode.com/problems/symmetric-tree/
 * By Nroskill
 * runtime 6 ms
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
    bool equal(TreeNode* a, TreeNode* b) {
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        return a->val == b->val && equal(a->left, b->right) && equal(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return equal(root->left, root->right); 
    }
};