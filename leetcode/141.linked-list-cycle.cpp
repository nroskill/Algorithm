/**
 * https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        auto one = head->next;
        auto two = head->next->next;
        while(one && two && two->next) {
            if(one == two)
                return true;
            one = one->next;
            two = two->next->next;
        }
        return false;
    }
};