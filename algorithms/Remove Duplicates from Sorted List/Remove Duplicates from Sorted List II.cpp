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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *nhead = new ListNode(0); 
        nhead->next = head; 
        auto last = nhead; 
        auto p = head; 
        while(p) {
            auto p1 = p->next; 
            while(p1 && p1->val == p->val) {
                p1 = p1->next; 
            }
            if(p1 != p->next) {
                last->next = p1;
            }
            else last = last->next;
            p = p1; 
        }
        return nhead->next; 
    }
};