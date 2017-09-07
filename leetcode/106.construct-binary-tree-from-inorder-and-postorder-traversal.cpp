/**
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * By Nroskill
 * runtime 12 ms
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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postEnd) {
        if(inStart == inEnd)
            return new TreeNode(inorder[inStart]);
        if(inStart > inEnd)
            return NULL;
        
        auto result = new TreeNode(postorder[postEnd]);
        int i = inStart;
        while(inorder[i++] != result->val);
        result->left = buildTree(inorder, inStart, i - 2, postorder, postEnd - inEnd + i - 2);
        result->right = buildTree(inorder, i, inEnd, postorder, postEnd - 1);
        return result;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, postorder.size() - 1);
    }
};