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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1, *p2;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        p1 = new_head;
        p2 = head; 
        ListNode *p2p = new_head;
        while(p2) {
            if(p2->val < x ) {
                if(p1->next == p2){
                    p1=p1->next; p2= p2->next; 
                    continue;
                }
                ListNode *p1_next = p1->next;
                ListNode *p2_next = p2->next;
                p1->next = p2;
                p2->next = p1_next;
                p2p->next = p2_next;
                p2 = p2_next;
                p1 = p1->next;
            }
            else {
                p2p = p2;
                p2 = p2->next;
            }
        }

        return new_head->next;
    }
};