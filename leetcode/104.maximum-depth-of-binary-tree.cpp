/**
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int right = maxDepth(root->right);
        int left  = maxDepth(root->left );
        return (right > left ? right : left) + 1;
    }
};