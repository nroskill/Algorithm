/**
 * https://leetcode.com/problems/merge-k-sorted-lists/
 * By Nroskill
 * runtime 39 ms
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
    struct compare{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto i : lists)
            if(i != NULL)
                pq.push(i);
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while(!pq.empty()) {
            temp->next = pq.top();
            temp = temp->next;
            pq.pop();
            if(temp->next)
                pq.push(temp->next);
        }
        return result->next;
    }
};