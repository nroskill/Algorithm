/**
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
 * By Nroskill
 * runtime 16 ms
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
    vector<TreeNode*> generateTrees(int n) {
        if(n < 1)
            return vector<TreeNode*>();
        return cal(1, n);
    }
    
    vector<TreeNode*> cal(int start, int end) {
        vector<TreeNode*> result;
        
        if(start == end) {
            result.push_back(new TreeNode(start));
            return result;
        }
        
        if(start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for(int i = start; i <= end; i++) {
            auto left = cal(start, i - 1);
            auto right = cal(i + 1, end);
            for(auto l : left) {
                for(auto r: right) {
                    auto t = new TreeNode(i);
                    t->left = l;
                    t->right = r;
                    result.push_back(t);
                }
            }
        }
        
        return result;
    }
};