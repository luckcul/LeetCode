/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getSize(ListNode* head) {
        int length = 0; 
        ListNode *p = head;
        while(p) {
            length ++; p = p->next;
        }
        return length; 
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int length = getSize(head);
        if(!length || length == 1) return head;
        k %= length; 
        if(!k) return head;
        ListNode *p = head; 
        int left = length - k; 
        int count = 0; 
        while(p) {
            count ++; 
            if(count >= left) {
                break;
            }
            p = p->next;
        }
        ListNode *pLeft = p;
        p = p->next;
        while(p) {
            count++; 
            if(count >= length) {
                break;
            }
            p = p->next;
        }
        p->next = head;
        ListNode *ret = pLeft->next;
        pLeft->next = NULL;
        return ret;
    }
};