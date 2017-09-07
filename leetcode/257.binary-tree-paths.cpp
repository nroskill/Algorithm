/**
 * https://leetcode.com/problems/binary-tree-paths/
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return vector<string>();
        if(!root->left && !root->right)
            return vector<string>({to_string(root->val)});
        vector<string> result;
        if(root->left) {
            auto r = binaryTreePaths(root->left);
            for(auto s : r)
                result.push_back(to_string(root->val) + "->" + s);
        }
        if(root->right) {
            auto r = binaryTreePaths(root->right);
            for(auto s : r)
                result.push_back(to_string(root->val) + "->" + s);
        }
        return result;
    }
};