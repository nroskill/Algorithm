/**
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * By Nroskill
 * runtime 22 ms
 * language cpp
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root, TreeLinkNode* next) {
        if(!root || !root->left || !root->right)
            return;
        root->left->next = root->right;
        root->right->next = next;
        connect(root->left, root->right->left);
        connect(root->right, (next && next->left) ? next->left : NULL);
    }
    
    void connect(TreeLinkNode *root) {
        if(!root || !root->left || !root->right)
            return;
        connect(root, NULL);
    }
};