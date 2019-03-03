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
    void adjust(TreeNode *par, TreeNode *root, TreeNode *final_node) {
        // if(!root) {
        //     par->right = final_node; 
        // }
        if(!root || root->val < final_node->val) {
            if(par) par->right = final_node; 
            final_node->left = root; 
            root = final_node; 
            return ; 
        }
        adjust(root, root->right, final_node); 
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode *final_node = new TreeNode(val); 
        TreeNode *par = new TreeNode(0); 
        par->right = root;
        adjust(par, root, final_node); 
        return par->right;
    }
};