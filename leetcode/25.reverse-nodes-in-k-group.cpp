/**
 * https://leetcode.com/problems/reverse-nodes-in-k-group/
 * By Nroskill
 * runtime 33 ms
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
    

    ListNode* reverseKGroup(ListNode* head, int k) {
        auto temp = head;
        for(int i = 1; i < k && temp; i++) {
            temp = temp->next;
        }
        if(temp == NULL)
            return head;
        temp = head;
        auto n = temp->next;
        auto save = head;
        head = new ListNode(0);
        head->next = temp;
        for(int i = 1; i < k; i++) {
            head->next = n;
            n = n->next;
            head->next->next = temp;
            temp = head->next;
        }
        save->next = reverseKGroup(n, k);
        save = head->next;
        delete head;
        return save;
    }
};