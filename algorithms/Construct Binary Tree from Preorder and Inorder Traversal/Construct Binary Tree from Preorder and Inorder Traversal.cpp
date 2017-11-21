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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size(), len2 = inorder.size(); 
        if(len1 == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int mid_index = -1;
        for(int i = 0; i < len2; i++) {
            if(inorder[i] == preorder[0]) {
                mid_index = i; break;
            }
        }
        vector<int> pre_left(preorder.begin()+1, preorder.begin()+mid_index+1);
        vector<int> pre_right(preorder.begin()+mid_index+1, preorder.end());
        vector<int> in_left(inorder.begin(), inorder.begin()+mid_index);
        vector<int> in_right(inorder.begin()+mid_index+1, inorder.end());
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};