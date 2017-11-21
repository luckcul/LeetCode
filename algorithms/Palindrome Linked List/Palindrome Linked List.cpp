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
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow) {
            if(head->val != slow->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode *new_head = new ListNode(0);
        while(head) {
            ListNode *next = head->next;
            ListNode *n_next = new_head->next;
            new_head->next = head;
            head->next = n_next;
            head = next;
        }
        return new_head->next;
    }
};