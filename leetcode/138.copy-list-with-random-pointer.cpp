/**
 * https://leetcode.com/problems/copy-list-with-random-pointer/
 * By Nroskill
 * runtime 66 ms
 * language cpp
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return NULL;
        auto i = head;
        auto t = head;
        while(i) {
            t = i->next;
            i->next = new RandomListNode(i->label);
            i = i->next;
            i->next = t;
            i = i->next;
        }
        i = head;
        t = i->next;
        while(i) {
            t->random = i->random ? i->random->next : NULL;
            i = t->next;
            if(i)
                t = i->next;
        }
        auto result = head->next;
        i = head;
        t = result;
        while(i) {
            i->next = t->next;
            i = i->next;
            if(i) {
                t->next = i->next;
                t = t->next;
            }
        }
        return result;
    }
};