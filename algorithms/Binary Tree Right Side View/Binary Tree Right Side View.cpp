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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        vector<vector<TreeNode*>> v(2, vector<TreeNode*>());
        if(root == NULL) return ret;
        int now = 0;
        v[now].push_back(root);
        while(v[now].size()) {
            ret.push_back(v[now][v[now].size()-1]->val);
            int next = now ^ 1;
            v[next].clear();
            for(int i = 0;i < v[now].size(); i++) {
                TreeNode * temp = v[now][i];
                if(temp->left) v[next].push_back(temp->left);
                if(temp->right) v[next].push_back(temp->right);
            }
            now = next;
        }        
        return ret;
    }
};