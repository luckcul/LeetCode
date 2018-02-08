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
    TreeNode *mark1, *mark2, *pre;
public:
    void recoverTree(TreeNode* root) {
        if(!root) return ;
        mark1 = mark2  = NULL;
        pre = new TreeNode(1<<31);
        recover(root);
        // swap opera
        swap(mark1->val, mark2->val);
    }
    void recover(TreeNode *root){
        if(root->left) recover(root->left); 
        if(!mark1 && pre->val >= root->val) mark1 = pre; 
        if(mark1 && pre->val >= root->val) mark2 = root; 
        pre = root; 
        if(root->right) recover(root->right);
    }
};