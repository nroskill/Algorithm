/**
 * https://leetcode.com/problems/count-complete-tree-nodes/
 * By Nroskill
 * runtime 86 ms
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int depth = 0;
        int maxDepth;
        for(auto t = root; t->left; t = t->left)
            depth++;
        maxDepth = depth;
        for(auto t = root; t->right; t = t->right)
            depth--;
        if(depth == 0)
            return (1 << (maxDepth + 1)) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};