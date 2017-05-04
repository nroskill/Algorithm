/**
 * https://leetcode.com/problems/convert-bst-to-greater-tree/
 * By Nroskill
 * runtime 39 ms
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
    int sum = 0;

    void cal(TreeNode* root) {
        if(root->right)
            cal(root->right);
        root->val += sum;
        sum = root->val;
        if(root->left)
            cal(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int ex = 0;
        if(!root)
            return NULL;
        cal(root);
        return root;
    }
};