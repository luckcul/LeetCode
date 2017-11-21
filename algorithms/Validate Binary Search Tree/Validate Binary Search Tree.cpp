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
    bool check(TreeNode *root, long long Min, long long Max) {
        if(!root) return true;
        if(root->val >= Max) return false;
        if(root->val <= Min) return false;
        if(!check(root->left, Min, min(Max, (long long) root->val)) || 
            !check(root->right, max(Min, (long long) root->val), Max)) return false;
        return true;
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, -1e10, 1e10);
        
    }
};