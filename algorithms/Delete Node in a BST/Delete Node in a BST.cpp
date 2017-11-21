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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if(root->left == NULL) {
                root = root->right;
            }
            else if(root->right == NULL) {
                root = root->left;
            }
            else {
                int minValue = findMin(root->right);
                root->val = minValue;
                root->right = deleteNode(root->right, minValue);
            }
        }
        return root;
    }
    int findMin(TreeNode *root) {
        int ret;
        while(root){
            ret = root->val;
            root = root->left;
        }
        return ret;
    }
};