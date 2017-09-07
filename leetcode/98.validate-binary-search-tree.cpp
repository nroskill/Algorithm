/**
 * https://leetcode.com/problems/validate-binary-search-tree/
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
    bool biggerThanLeft (TreeNode* root) {
        if(!root->left)
            return true;
        auto p = root->left;
        while(p->right)
            p = p->right;
        return root->val > p->val;
    }
    
    bool smallerThanRight(TreeNode* root) {
        if(!root->right)
            return true;
        auto p = root->right;
        while(p->left)
            p = p->left;
        return root->val < p->val;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        else
            return isValidBST(root->left) && isValidBST(root->right) && biggerThanLeft(root) && smallerThanRight(root);
    }
};