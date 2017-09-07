/**
 * https://leetcode.com/problems/binary-search-tree-iterator/
 * By Nroskill
 * runtime 32 ms
 * language cpp
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode* _root;
    
public:
    BSTIterator(TreeNode *root) {
        _root = root;
        if(!root)
            return;
        stack<TreeNode*> helper;
        if(root->left)
            helper.push(root->left);
        if(root->right)
            helper.push(root->right);
        _root->left = _root->right = NULL;
        while(!helper.empty()) {
            auto t = helper.top();
            helper.pop();
            if(t->left)
                helper.push(t->left);
            if(t->right)
                helper.push(t->right);
            t->left = t->right = NULL;
            auto i = _root;
            while((t->val < i->val && i->left) || (t->val > i->val && i->right))
                i = t->val < i->val ? i->left : i->right;
            if(t->val < i->val)
                i->left = t;
            else
                i->right = t;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return _root != NULL;
    }

    /** @return the next smallest number */
    int next() {
        auto i = _root;
        if(!_root->left) {
            _root = _root->right;
            return i->val;
        }
        while(i->left->left)
            i = i->left;
        auto t = i->left;
        i->left = t->right;
        return t->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */