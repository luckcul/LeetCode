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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        vector<vector<TreeNode *>> temp(2, vector<TreeNode *>());
        int now = 0;
        temp[now].push_back(root);
        while(temp[now].size() != 0) {
            int next = now ^ 1;
            temp[next].clear();
            for(int i = 0; i < temp[now].size(); i++) {
                TreeNode *tempNode = temp[now][i];
                swap(tempNode->right, tempNode->left);
                if(tempNode->left) temp[next].push_back(tempNode->left);
                if(tempNode->right) temp[next].push_back(tempNode->right);
            }
            now = next;
        }
        return root;
    }
};