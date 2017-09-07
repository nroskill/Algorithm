/**
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* BuildTree(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        TreeNode* result = new TreeNode(nums[(start + end) / 2]);
        result->left  = BuildTree(nums, start, (start + end) / 2 - 1);
        result->right = BuildTree(nums, (start + end) / 2 + 1, end);
        return result;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BuildTree(nums, 0, nums.size() - 1);
    }
};