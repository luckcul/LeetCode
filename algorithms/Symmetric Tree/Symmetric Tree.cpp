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
    bool mirrors(TreeNode *root_left, TreeNode *root_right) {
        if(!root_left && !root_right) return true;
        if(!root_left || !root_right) return false;
        if(root_left->val != root_right->val) return false;
        bool ret1 = mirrors(root_left->left, root_right->right);
        bool ret2 = mirrors(root_left->right, root_right->left);
        return ret1 && ret2;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return mirrors(root->left, root->right);
    }
};