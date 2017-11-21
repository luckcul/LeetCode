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
    int maxDepth(TreeNode* root) {
        if(!root) return 0; 
        int depth_left = maxDepth(root->left);
        int depth_right = maxDepth(root->right);
        return max(depth_left, depth_right) + 1;
    }
};