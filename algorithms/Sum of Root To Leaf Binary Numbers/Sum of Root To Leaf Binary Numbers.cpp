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
    long long sums; 
    long long mod; 
    long long dfs(TreeNode *root) {
        if(!root) return 0; 
        long long ret = 0; 
        if(root->left) {
            ret += 2*dfs(root->left); 
            ret %= mod; 
        }
        if(root->right) {
            ret += 2*dfs(root->right); 
            ret %= mod; 
        }
        if(!ret) ret = 1; 
        sums += root->val * ret; 
        sums %= mod; 
        return ret; 
    }
    int sumRootToLeaf(TreeNode* root) {
        sums = 0; 
        mod = 1000000007;
        dfs(root); 
        return sums; 
    }
};