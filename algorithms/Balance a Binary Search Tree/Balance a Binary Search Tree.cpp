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
    vector<int> num; 
public:
    void dfs(TreeNode * root) {
        if(!root) return; 
        dfs(root->left); 
        num.push_back(root->val); 
        dfs(root->right); 
    }
    
    TreeNode * construct_btree(int s_idx, int e_idx) {
        if(s_idx>e_idx) return NULL; 
        int m_idx = (s_idx + e_idx) / 2; 
        TreeNode * root = new TreeNode(num[m_idx]); 
        root->left = construct_btree(s_idx, m_idx-1); 
        root->right = construct_btree(m_idx+1, e_idx); 
        return root; 
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root); 
        int size = num.size(); 
        return construct_btree(0, size-1); 
    }
};