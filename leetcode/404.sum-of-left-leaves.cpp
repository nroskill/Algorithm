/**
 * https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumLeft(TreeNode* root, bool isLeft) {
        if(!root)
            return 0;
        if(isLeft && !root->left && !root->right)
            return root->val;
        return sumLeft(root->left, true) + sumLeft(root->right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        return sumLeft(root, false);
    }
};