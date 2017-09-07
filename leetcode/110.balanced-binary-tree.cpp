/**
 * https://leetcode.com/problems/balanced-binary-tree/
 * By Nroskill
 * runtime 9 ms
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
    int depth(TreeNode* root) {
        if(!root)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};