/**
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * By Nroskill
 * runtime 29 ms
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
    void cal(unordered_map<int, int>& db, TreeNode* root, int& maxFre) {
        if(!root)
            return;
        if(db[root->val] == 0)
            db[root->val] = 1;
        else
            db[root->val]++;
        maxFre = max(db[root->val], maxFre);
        cal(db, root->left, maxFre);
        cal(db, root->right, maxFre);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> db;
        int maxFre = 0;
        vector<int> result;
        cal(db, root, maxFre);
        for(auto iterator = db.begin(); iterator != db.end(); iterator++)
            if(iterator->second == maxFre)
                result.push_back(iterator->first);
        return result;
    }
};