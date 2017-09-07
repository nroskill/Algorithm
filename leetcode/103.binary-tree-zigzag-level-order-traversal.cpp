/**
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
    void build(vector<vector<int>>& result, TreeNode* root, int depth) {
        if(!root)
            return;
        if(result.size() == depth)
            result.push_back(vector<int>());
        result[depth].push_back(root->val);
        build(result, root->left, depth + 1);
        build(result, root->right, depth + 1);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        build(result, root, 0);
        for(int i = 1; i < result.size(); i += 2)
            reverse(result[i].begin(), result[i].end());
        return result;
    }
};