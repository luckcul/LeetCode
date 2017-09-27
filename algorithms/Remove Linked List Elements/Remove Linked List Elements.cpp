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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;
        ListNode newHead(1);
        ListNode *nhead = &newHead, *p;
        nhead->next = head;
        p = nhead;
        cout<<p->next->val<<endl;
        while(p->next) {
            if(p->next->val == val) {
                p->next = p->next->next;
            }
            else p = p->next;
        }
        return nhead ? nhead->next : NULL;
    }
};