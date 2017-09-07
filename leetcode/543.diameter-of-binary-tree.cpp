/**
 * https://leetcode.com/problems/diameter-of-binary-tree/
 * By Nroskill
 * runtime 15 ms
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
    int result = 0;
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return -1;
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        result = max(result, left + right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return result;
    }
};