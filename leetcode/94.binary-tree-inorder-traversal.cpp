/**
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * By Nroskill
 * runtime 0 ms
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> save;
        vector<int> result;
        auto cur = root;
        while(cur || !save.empty()) {
            if(cur) {
                save.push(cur);
                cur = cur->left;
            }
            else {
                cur = save.top();
                save.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }
};