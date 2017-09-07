/**
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        auto t = root->right;
        root->right = root->left;
        root->left = NULL;
        flatten(root->right);
        auto p = root;
        while(p->right)
            p = p->right;
        p->right = t;
        flatten(t);
    }
};