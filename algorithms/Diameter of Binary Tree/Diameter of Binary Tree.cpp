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
    int dfs(TreeNode *root, int &max_diameter){
        if(!root) return 0; 
        int left_depth = dfs(root->left, max_diameter);
        int right_depth = dfs(root->right, max_diameter);
        // cout<<"val : "<<root->val<<" "<<left_depth<<" "<<right_depth<<endl;
        max_diameter = max(max_diameter, left_depth + right_depth + 1);
        return max(left_depth, right_depth) + 1; 
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0; 
        int ret = 0; 
        dfs(root, ret); 
        return ret - 1; 
    }
};