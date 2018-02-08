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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        pre_dfs(root, ret);
        return ret;
    }
    void pre_dfs(TreeNode *root, vector<int> &ret) {
        if(!root) return ;
        ret.push_back(root->val);
        pre_dfs(root->left, ret); 
        pre_dfs(root->right, ret);
    }
};