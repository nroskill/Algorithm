/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
private:
    int count(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + count(root->left) + count(root->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        while(true) {
            int c = count(root->left);
            if(c + 1 == k)
                return root->val;
            else if(c + 1 < k) {
                root = root->right;
                k -= (c + 1);
            }
            else
                root = root->left;
        }
        return 0;
    }
};