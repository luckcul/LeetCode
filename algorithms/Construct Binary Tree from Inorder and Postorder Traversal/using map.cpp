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
    unordered_map<int, int> M;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_length = inorder.size(); 
        int post_length = postorder.size(); 
        for(int i = 0; i < in_length; i++) {
            M[inorder[i]] = i;
        }
        return sol(inorder, postorder, 0, in_length, 0, post_length);
    }
    TreeNode* sol(vector<int>& inorder, vector<int>& postorder, int in_s, int in_e, int post_s, int post_e) {
        if(in_s >= in_e) return NULL;
        int root_val = postorder[post_e-1];
        TreeNode *root = new TreeNode(root_val);
        int index = M[root_val];
        root->left = sol(inorder, postorder, in_s, index, post_s, post_s + (index-in_s));
        root->right = sol(inorder, postorder, index+1, in_e, post_s + (index-in_s), post_e-1);
        return root;
    }
};