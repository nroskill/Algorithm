/**
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
 * By Nroskill
 * runtime 28 ms
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
    void cal(TreeNode* root, int& lastOne, int& min) {
        if(root->left)
            cal(root->left, lastOne, min);
        if(lastOne >= 0)
            min = std::min(min, root->val - lastOne);
        lastOne = root->val;
        if(root->right)
            cal(root->right, lastOne, min);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int min = 0x7fffffff, lastOne = -1;
        cal(root, lastOne, min);
        return min;
    }
};