/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    ListNode *p;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int length = 0;
        this->p = head;
        ListNode *p = head;
        while(p) {
            length ++; 
            p = p->next;
        }
        return toBST(0, length-1);
    }
    TreeNode* toBST(int l, int r) {
        if(l > r) return NULL;
        int m = (l+r)/2;
        TreeNode *left = toBST(l, m-1); 
        TreeNode *ret = new TreeNode(this->p->val);
        this->p = this->p->next;
        TreeNode *right = toBST(m+1, r);
        ret->left = left;
        ret->right = right;
        return ret;
    }
};