/**
 * https://leetcode.com/problems/path-sum-ii/
 * By Nroskill
 * runtime 13 ms
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
    void helper(vector<vector<int>>& result, TreeNode* root, int sum, vector<int> current) {
        if(!root)
            return;
        current.push_back(root->val);
        if(!root->left && !root->right && root->val == sum) {
            result.push_back(current);
            return;
        }
        helper(result, root->left, sum - root->val, current);
        helper(result, root->right, sum - root->val, current);
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        helper(result, root, sum, vector<int>());
        return result;
    }
};