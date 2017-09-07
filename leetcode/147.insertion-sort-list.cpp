/**
 * https://leetcode.com/problems/insertion-sort-list/
 * By Nroskill
 * runtime 49 ms
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
    ListNode* insertionSortList(ListNode* head) {
        auto result = new ListNode(0);
        while(head) {
            auto t = head;            
            head = head->next;
            auto i = result;
            while(i->next) {
                if(i->next->val > t->val)
                    break;
                i = i->next;
            }
            t->next = i->next;
            i->next = t;
        }
        return result->next;
    }
};