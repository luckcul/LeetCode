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
    int ret = 0; 
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root); 
        return ret; 
    }
    int dfs(TreeNode *root) {
        if(!root) return 0; 
        int left_val = dfs(root->left), right_val = dfs(root->right); 
        if(! root->left || root->val != root->left->val) {
            left_val = 0; 
        }
        if(!root->right || root->val != root->right->val) {
            right_val = 0; 
        }
        this->ret = max(this->ret, left_val + right_val); 
        // printf("val: %d lr: %d %d \n", root->val, left_val, right_val);
        return max(left_val, right_val) + 1; 
    }
};