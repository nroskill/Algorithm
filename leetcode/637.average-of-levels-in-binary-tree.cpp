/**
 * https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode*> temp;
        int c = 0;
        if(root) {
            c++;
            temp.push(root);
        }
        
        while(!temp.empty()) {
            result.push_back(0.0);
            int t = 0;
            for(int i = 0; i < c; i++) {
                result[result.size() - 1] += temp.front()->val;
                if(temp.front()->left) {
                    t++;
                    temp.push(temp.front()->left);
                }
                if(temp.front()->right) {
                    t++;
                    temp.push(temp.front()->right);
                }
                temp.pop();
            }
            result[result.size() - 1] /= c;
            c = t;
        }
        return result;
    }
};