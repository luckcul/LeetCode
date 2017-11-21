/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *help(ListNode *p, ListNode *head) {
        ListNode *ret_p = head;
        while(p) {
            p = p->next;
            ret_p = ret_p->next;
        }
        return ret_p;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1 && p2) {
            if(p1 == p2) return p1;
            p1 = p1->next; 
            p2 = p2->next;
        }
        if(p1) {
            p1 = help(p1, headA);
            p2 = headB;
        }
        else {
            p2 = help(p2, headB);
            p1 = headA;
        }
        while(p1 && p2) {
            if(p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};