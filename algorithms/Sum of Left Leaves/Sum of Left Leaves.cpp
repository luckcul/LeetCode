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
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0; 
        int ret = 0; 
        if(root->left && !(root->left->right) && !(root->left->left)) ret += root->left->val; 
        ret += sumOfLeftLeaves(root->left);
        ret += sumOfLeftLeaves(root->right);
        return ret; 
    }
};