/**
 * https://leetcode.com/problems/binary-tree-right-side-view/
 * By Nroskill
 * runtime 3 ms
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
    void helper(TreeNode* root, vector<int>& ret, int depth) {
        if(!root)
            return;
        if(depth == ret.size())
            ret.push_back(root->val);
        helper(root->right, ret, depth + 1);
        helper(root->left , ret, depth + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        helper(root, result, 0);
        return result;
    }
};