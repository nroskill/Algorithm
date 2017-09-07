/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * By Nroskill
 * runtime 13 ms
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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        auto t = head;
        while(t->next)
            if(t->val == t->next->val)
                t->next = t->next->next;
            else
                t = t->next;
        return head;
    }
};