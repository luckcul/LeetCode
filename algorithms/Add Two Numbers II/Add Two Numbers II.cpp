/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 class Solution {
    ListNode* reverseList(ListNode *head) {
        ListNode temp(0);
        ListNode *nHead = &temp, *p = head;
        while(p) {
            ListNode *next = nHead->next, *pnext = p->next;
            nHead->next = p;
            p->next = next;
            p = pnext;
        }
        return nHead->next;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *re_l1 = reverseList(l1);
        ListNode *re_l2 = reverseList(l2);
        ListNode *ret = (ListNode *)malloc(sizeof(ListNode)), *p1 = re_l1, *p2 = re_l2;
        ListNode *p = ret;
        int last = 0;
        bool flag = true;
        while(true) {
            int s = (p1? p1->val : 0) + (p2? p2->val : 0) + last;
            if(s == 0 && !p1 && !p2) break;
            last = s / 10;
            s %= 10;
            // ListNode sNode(s);
            ListNode *pNode = (ListNode *)malloc(sizeof(ListNode));
            pNode->val = s;
            p->next = pNode;
            p = p->next;
            cout<<p->val<<endl;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }
        p->next = NULL;
        ListNode *re = reverseList(ret->next);
        return re;
    }
};