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
    int convert(TreeNode *root, int parent_sum) {
        if(!root) return 0;
        int right = convert(root->right, parent_sum);
        int left = convert(root->left, parent_sum + root->val + right);
        int sum = root->val + right;
        root->val += right + parent_sum;
        return sum + left;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }
};