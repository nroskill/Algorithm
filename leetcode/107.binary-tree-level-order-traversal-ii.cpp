/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
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
    void helper(vector<vector<int>>& result, TreeNode* root, int depth) {
        if(!root)
            return;
        if(depth == result.size())
            result.push_back(vector<int>());
        result[depth].push_back(root->val);
        helper(result, root->left, depth + 1);
        helper(result, root->right, depth + 1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        helper(result, root, 0);
        reverse(result.begin(), result.end());
        return result;
    }
};