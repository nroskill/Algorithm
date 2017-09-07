/**
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * By Nroskill
 * runtime 39 ms
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
    void connect(TreeLinkNode *root, TreeLinkNode *next) {
        if(root->right) {
            root->right->next = next;
            auto p = next;
            for(;p ; p = p->next)
                if(p->left || p->right)
                    break;
            connect(root->right, !p ? NULL : (p->left ? p->left : p->right));
        }
        if(root->left) {
            root->left->next = root->right ? root->right : next;
            auto p = root->left->next;
            for(; p; p = p->next)
                if(p->left || p->right)
                    break;
            connect(root->left, !p ? NULL : (p->left ? p->left : p->right));
        }
    }
    
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        connect(root, NULL);
    }
};