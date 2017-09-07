/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * By Nroskill
 * runtime 9 ms
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
        ListNode* result = new ListNode(0);
        result->next = head;
        for(ListNode* i = result; i && i->next;) {
            int val = i->next->val;
            if(!i->next->next)
                return result->next;
            if(i->next->next->val == val)
                while(i->next && i->next->val == val)
                    i->next = i->next->next;
            else
                i = i->next;
        }
        return result->next;
    }
};