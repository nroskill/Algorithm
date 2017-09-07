/**
 * https://leetcode.com/problems/add-two-numbers/
 * By Nroskill
 * runtime 26 ms
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int over = 0;
        ListNode* p,* result;
        p = result = new ListNode(0);
        while(1)
        {
            if(!l1 && !l2)
            {
                if(over)
                    p -> next = new ListNode(over);
                break;
            }
            p -> next = new ListNode(((l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + over) % 10);
            p = p -> next;
            over = ((l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + over) / 10;
            if(l1)
                l1 = l1 -> next;
            if(l2)
                l2 = l2 -> next;
        }
        p = result -> next;
        delete result;
        return p;
    }
};