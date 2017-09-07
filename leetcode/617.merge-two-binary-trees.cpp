/**
 * https://leetcode.com/problems/merge-two-binary-trees/
 * By Nroskill
 * runtime 43 ms
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2)
            return NULL;
        TreeNode* result = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
        result->left  = mergeTrees(t1 ? t1->left  : NULL, t2 ? t2->left  : NULL);
        result->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return result;
    }
};