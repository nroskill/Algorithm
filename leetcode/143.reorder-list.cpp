/**
 * https://leetcode.com/problems/reorder-list/
 * By Nroskill
 * runtime 809 ms
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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        auto i = head;
        while(i->next->next)
            i = i->next;
        i->next->next = head->next;
        head->next = i->next;
        i->next = NULL;
        reorderList(head->next->next);
    }
};