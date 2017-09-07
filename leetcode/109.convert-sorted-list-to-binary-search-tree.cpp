/**
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * By Nroskill
 * runtime 22 ms
 * language cpp
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if(!head || head == tail)
            return NULL;
        if(head->next == tail)
            return new TreeNode(head->val);
        auto slow = head;
        auto fast = head;
        while(fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, tail);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return NULL;
        return sortedListToBST(head, NULL);
    }
};