/**
 * https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* t;
        int n = 1;
        for(t = head; t->next; t = t->next)
            n++;
        t->next = head;
        k = n - k % n;
        while(--k > 0)
            head = head->next;
        t = head->next;
        head->next = NULL;
        return t;
    }
};