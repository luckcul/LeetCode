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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *p = head, *second = NULL;
        if(!head) return head;
        second = head->next;
        // cout<<second->val<<endl;
        int count = 0;
        while(p) {
            count ++;
            ListNode *pNext = p->next;
            if(p->next){
                p->next = p->next->next;
            }
            if((count & 1) && (pNext == NULL || pNext->next == NULL)){
                p->next = second;
                // cout<<p->next->val<<"."<<second->val<<endl;
            }
            p = pNext;
            // cout<<p->val<<endl;
        }
        return head;
    }
};