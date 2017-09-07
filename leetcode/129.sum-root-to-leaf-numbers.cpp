/**
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void sumNumbers(TreeNode* root, int& result, int current) {
        if(!root)
            return;
        current = current * 10 + root->val;
        if(!root->left && !root->right) {
            result += current;
            return;
        }
        if(root->left)
            sumNumbers(root->left, result, current);
        if(root->right)
            sumNumbers(root->right, result, current);
        
    }
    
    int sumNumbers(TreeNode* root) {
        int result = 0;
        sumNumbers(root, result, 0);
        return result;
    }
};