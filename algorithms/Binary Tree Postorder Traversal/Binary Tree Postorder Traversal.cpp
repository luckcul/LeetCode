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
    void postorDfs(TreeNode *root, vector<int> &ret) {
        if(!root) return ;
        postorDfs(root->left, ret);
        postorDfs(root->right, ret); 
        ret.push_back(root->val); 
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret; 
        postorDfs(root, ret); 
        return ret;
    }
};