/**
 * https://leetcode.com/problems/reverse-linked-list/
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
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL, * next;
        while(head) {
            next = head->next; 
            head->next = last;
            last = head;
            head = next;
        }
        return last;
    }
};