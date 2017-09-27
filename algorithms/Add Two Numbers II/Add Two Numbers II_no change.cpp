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
        stack<int> s1, s2;
        ListNode *p1 = l1, *p2 = l2;
        while(p1) {
            s1.push(p1->val);
            p1 = p1->next;
        }
        while(p2) {
            s2.push(p2->val);
            p2 = p2->next;
        }
        ListNode *nhead = new ListNode(0), *p = nhead;
        int last= 0;
        while(true) {
            int num1 = s1.empty() ? 0 : s1.top();
            int num2 = s2.empty() ? 0 : s2.top();
            int s = num1 + num2 + last;
            if(!s && s1.empty() && s2.empty()) break;
            last = s / 10;
            s %= 10;
            ListNode *now = new ListNode(s);
            ListNode *headNext = nhead->next;
            nhead->next = now;
            now->next = headNext;
            if(!s1.empty()) s1.pop();
            if(!s2.empty()) s2.pop();
        }
        return nhead->next;
    }
};