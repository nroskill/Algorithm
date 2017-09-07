/**
 * https://leetcode.com/problems/intersection-of-two-linked-lists/
 * By Nroskill
 * runtime 46 ms
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headB || !headA)
            return NULL;

        auto save = headB;
        while(save->next)
            save = save->next;
        save->next = headB;
        
        if(!headA->next) {
            save->next = NULL;
            return NULL;
        }

        auto one = headA->next;
        auto two = headA->next->next;
        while(one != two) {
            one = one->next;
            if(!two || !two->next) {
                save->next = NULL;
                return NULL;
            }
            two = two->next->next;
        }
        two = headA;
        while(one != two) {
            one = one->next;
            two = two->next;
        }
        save->next = NULL;
        return one;
    }
};