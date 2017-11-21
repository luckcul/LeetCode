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
        ListNode *nhead = new ListNode(0);
        ListNode *p = head; 
        while(p) {
            ListNode *pnext = p->next, *headNext = nhead->next;
            nhead->next = p;
            p->next = headNext;
            p = pnext;
        }
        return nhead->next;
    }
};