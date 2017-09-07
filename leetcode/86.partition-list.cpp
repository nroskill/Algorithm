/**
 * https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* result = new ListNode(0);
        ListNode* p1 = head;
        head = new ListNode(0);
        head->next = p1;
        p1 = result;
        ListNode* p2 = head;
        while(p2->next) {
            if(p2->next->val < x) {
                p1->next = p2->next;
                p1 = p1->next;
                p2->next = p1->next;
            }
            else
                p2 = p2->next;
        }
        p1->next = head->next;
        return result->next;
    }
};