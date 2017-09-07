/**
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> temp;
        if(!root)
            return result;
        queue<TreeNode*> save;
        save.push(root);
        int c = 1, ct = 0;
        while(!save.empty()) {
            auto t = save.front();
            save.pop();
            temp.push_back(t->val);
            if(t->left) {
                ct++;
                save.push(t->left);
            }
            if(t->right) {
                ct++;
                save.push(t->right);
            }
            if(--c == 0) {
                result.push_back(temp);
                temp.clear();
                c = ct;
                ct = 0;
            }
        }
        return result;
    }
};