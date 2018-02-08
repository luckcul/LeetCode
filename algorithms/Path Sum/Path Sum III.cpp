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
    int ret; 
public:
    int pathSum(TreeNode* root, int sum) {
        ret = 0; 
        dfs(root, sum); 
        return ret; 
    }
    void dfs(TreeNode *root, int sum) {
        if(!root) return ; 
        sol(root, 0, sum, 0);
        cout<<root->val<<":"<<ret<<endl;
        dfs(root->left, sum); 
        dfs(root->right, sum); 
    }
    void sol(TreeNode *root, int prev, int sum, int depth) {
        if(prev == sum && depth > 0) {
            ret ++; 
        }
        if(!root) return ; 
        sol(root->left, prev + root->val, sum, depth+1); 
        sol(root->right, prev + root->val, sum, depth+1);
    }
};