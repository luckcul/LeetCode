/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    pair<ListNode *, ListNode *> findNodes(ListNode *head, int m, int n) {
        int count = 0; 
        pair<ListNode *, ListNode *> ret;
        ListNode *p = head;
        while(p) {
            count ++; 
            if(count == m) {
                // cout<<p->val<<endl;
                ret.first = p;
            }
            if(count - 1 == n) {
                // cout<<p->val<<"ok"<<endl;
                ret.second = p;
                return ret;
            }
            p = p->next;
        }
        return ret;
    }
    void reverseList(ListNode *p1, ListNode * p2) {
        // cout<<p1->val<<" "<<p2->val<<endl;
        ListNode *p = p1->next, *p2Next = p2->next;
        p1->next = p2->next;
        while(p != p2Next) {
            // cout<<p->val<<" "<<p2Next->val<<endl;
            ListNode *pNext = p->next, *p1Next = p1->next;
            p1->next = p;
            p->next = p1Next;
            p = pNext;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *nhead = new ListNode(0);
        nhead->next = head;
        pair<ListNode *, ListNode *> p = findNodes(nhead, m, n);
        reverseList(p.first, p.second);
        return nhead->next;
    }
};