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
    void dfs(TreeNode* root, int &sum, int p) {
        if(!root) {
            return ;
        }
        p *= 10; p += root->val; 
        if(root->left) dfs(root->left, sum, p);
        if(root->right) dfs(root->right, sum, p);
        if(!root->left && !root->right) sum += p;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ret = 0; 
        dfs(root, ret, 0);
        return ret;
    }
};