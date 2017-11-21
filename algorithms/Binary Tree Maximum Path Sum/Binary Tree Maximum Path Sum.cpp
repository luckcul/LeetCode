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
    int dfs(TreeNode *root, int &global_max) {
        if(!root) return 0; 
        int left_val = dfs(root->left, global_max);
        int right_val = dfs(root->right, global_max);
        left_val = max(0, left_val); right_val = max(0, right_val);
        global_max = max(global_max, left_val + right_val + root->val);
        return max(left_val, right_val) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int global_max = -1000000000;
        dfs(root, global_max);
        return global_max;
    }
};