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
    void reorderList(ListNode* head) {
        if(!head) return ; 
        int length = 0; 
        ListNode *p = head; 
        while(p) {
            length ++; 
            p = p->next;
        }
        if(length <= 2) return ;
        int start_index = length - length/2+1;
        int cnt = 0; 
        p = head;
        ListNode *last = NULL, *last_one = NULL;
        while(p) {
            cnt ++;
            auto next = p->next;
            if(cnt >= start_index) {
                p->next = last;
                last = p;
            }
            if(cnt == length/2+1) last_one = p;
            p = next;
        }
        auto p1 = head, p2 = last;
        for(int i = 0; i < length/2; i++) {
            auto p1_next = p1->next, p2_next = p2->next;
            p1->next = p2;
            p2->next = p1_next;
            p1 = p1_next, p2 = p2_next;
        }
        last_one->next = NULL;
    }
};