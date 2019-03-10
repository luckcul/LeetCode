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
    TreeNode *sol(vector<int> &preorder, int i, int j ) {
        if(j < i) return NULL; 
        TreeNode *root = new TreeNode(preorder[i]); 
        int root_val = preorder[i]; 
        int idx = i+1; 
        for(; idx <= j; idx++) {
            if(preorder[idx] > root_val) break;
        }
        root->left = sol(preorder, i+1, idx-1);
        root->right = sol(preorder, idx, j);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return sol(preorder, 0, preorder.size()-1);
    }
};