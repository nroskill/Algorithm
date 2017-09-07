/**
 * https://leetcode.com/problems/linked-list-cycle-ii/
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
    //one run n * r + s + a
    //two run (n + 1) * r + s + a
    //two == 2 * one
    //s + a == (1-n)r > 0
    //n == 0
    //s + a == r
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return NULL;
        auto one = head->next;
        auto two = one->next;
        while(one != two) {
            one = one->next;
            if(!two || !two->next)
                return NULL;
            two = two->next->next;
        }
        while(one != head) {
            one = one->next;
            head = head->next;
        }
        return head;
    }
};