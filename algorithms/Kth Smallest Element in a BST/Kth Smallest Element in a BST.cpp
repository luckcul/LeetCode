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
    int find(TreeNode *root, int k, int parent_sum, int &ret){
        if(!root) return 0; 
        int left_sum = find(root->left, k, parent_sum, ret);
        cout<<parent_sum<<" "<<left_sum<<endl;
        if(parent_sum + left_sum + 1 == k) ret = root->val;
        int right_sum = find(root->right, k, parent_sum + left_sum + 1, ret);
        return left_sum + right_sum + 1;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        find(root, k, 0, ret);
        return ret;
    }
};