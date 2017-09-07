/**
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int minD = INT_MAX;
        if(root->left)
            minD = min(minD, minDepth(root->left));
        if(root->right)
            minD = min(minD, minDepth(root->right));
        return minD + 1;
    }
};