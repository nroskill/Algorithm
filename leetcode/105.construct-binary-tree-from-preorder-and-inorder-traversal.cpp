/**
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * By Nroskill
 * runtime 19 ms
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
    TreeNode* buildTree(vector<int>& preorder, int preStart, vector<int>& inorder, int inStart, int inEnd) {
        if(inStart > inEnd)
            return NULL;
        if(inStart == inEnd)
            return new TreeNode(preorder[preStart]);
        
        auto result = new TreeNode(preorder[preStart]);
        int i = inStart;
        while(inorder[i++] != result->val);
        result->left = buildTree(preorder, preStart + 1, inorder, inStart, i - 2);
        result->right = buildTree(preorder, preStart + i - inStart, inorder, i, inEnd);
        return result;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
    }
};