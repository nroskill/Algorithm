/**
 * https://leetcode.com/problems/reverse-linked-list-ii/
 * By Nroskill
 * runtime 3 ms
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        auto t = new ListNode(0);
        t->next = head;
        head = t;
        auto begin = head;
        auto end = head;
        int i;
        for(i = 1; i < m; i++) {
            begin = begin->next;
            end = end->next;
        }
        t = begin->next;
        end = end->next;
        for(; i <= n; i++)
            end = end->next;
        ListNode* prev = end;
        ListNode* next = t->next;
        for(i = 0; i <= n - m; i++) {
            t->next = prev;
            prev = t;
            t = next;
            if(t)
                next = t->next;
        }
        begin->next = prev;

        t = head;
        head = head->next;
        delete t;
        return head;
    }
};