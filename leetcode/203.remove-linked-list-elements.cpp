/**
 * https://leetcode.com/problems/remove-linked-list-elements/
 * By Nroskill
 * runtime 29 ms
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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head->val == val)
            head = head->next;
        if(!head)
            return NULL;
        for(auto i = head; i->next;)
            if(i->next->val == val)
                i->next = i->next->next;
            else
                i = i->next;
        return head;
    }
};