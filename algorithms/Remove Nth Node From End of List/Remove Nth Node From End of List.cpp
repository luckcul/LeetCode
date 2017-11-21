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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *nhead = new ListNode(0);
        nhead->next = head;
        ListNode *p1 = nhead, *p2 = nhead; 
        for(int i = 0; i <= n; i++) {
            p2 = p2->next;
        }
        while(p1 && p2) {
            p1 = p1->next; 
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return nhead->next;
    }
};