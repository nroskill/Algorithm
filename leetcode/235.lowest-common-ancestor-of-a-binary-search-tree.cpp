/**
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 * By Nroskill
 * runtime 26 ms
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            return lowestCommonAncestor(root, q, p);
        if(p->val == q->val)
            return p;
        if(root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        if(q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};