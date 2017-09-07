/**
 * https://leetcode.com/problems/palindrome-linked-list/
 * By Nroskill
 * runtime 32 ms
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
private:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* prev = NULL, * cur = head,* next = head->next;
        while(next) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }

public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        auto t = new ListNode(0);
        t->next = head;
        head = t;
        auto one = head, two = head;
        while(two && two->next) {
            one = one->next;
            two = two->next->next;
        }
        if(!two) {
            t = new ListNode(one->val);
            t->next = one->next;
        }
        else
            t = one->next;
        one->next = NULL;
        one = head;
        head = head->next;
        delete one;
        t = reverse(t);
        while(head && t) {
            if(head->val != t->val)
                return false;
            head = head->next;
            t = t->next;
        }
        return head == t;
    }
};