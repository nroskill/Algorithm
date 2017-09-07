/**
 * https://leetcode.com/problems/swap-nodes-in-pairs/
 * By Nroskill
 * runtime 6 ms
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* t = head->next;
        ListNode* ret = t;
        while(true) {
            head->next = t->next;
            t->next = head;
            if(head->next && head->next->next) {
                t = head->next;
                head->next = t->next;
                head = t;
                t = head->next;
            }
            else
                break;
        }
        return ret;
    }
};