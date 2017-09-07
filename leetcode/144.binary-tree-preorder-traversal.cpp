/**
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> save;
        if(!root)
            return result;
        save.push(root);
        while(!save.empty()) {
            auto t = save.top();
            save.pop();
            result.push_back(t->val);
            if(t->right)
                save.push(t->right);
            if(t->left)
                save.push(t->left);
        }
        return result;
    }
};