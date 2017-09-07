/**
 * https://leetcode.com/problems/sort-list/
 * By Nroskill
 * runtime 56 ms
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
    ListNode* merge(ListNode* front, ListNode* back) {
        if(!front && !back)
            return NULL;
        if(!front || !back)
            return front ? front : back;
        ListNode* result;
        if(front->val < back->val) {
            result = front;
            front = front->next;
        }
        else {
            result = back;
            back = back->next;
        }
        auto i = result;
        while(front && back) {
            if(front->val < back->val) {
                i->next = front;
                front = front->next;
            }
            else {
                i->next = back;
                back = back->next;
            }
            i = i->next;
        }
        i->next = front ? front : back;
        return result;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        auto one = head;
        auto two = head;
        auto pre = head;
        while(two && two->next) {
            pre = one;
            one = one->next;
            two = two->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(one));
    }
};