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
        ListNode *nHead = new ListNode(0), *p = nHead, *p1 = l1, *p2 = l2;
        int last = 0;
        while(true) {
            if(!last && !p1 && !p2) break;
            int s = last + (p1? p1->val : 0) + (p2? p2->val:0);
            last = s / 10;
            s %= 10;
            ListNode *temp = new ListNode(s);
            p->next = temp;
            // cout<<temp->val<<endl;
            p = p->next;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }      
        return nHead->next;
    }
};