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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret; 
        dfs(root, 0, ret);
        return ret;
    }
    void dfs(TreeNode* root, int depth, vector<int> &ret) {
        if(!root) return ;
        if(ret.size() <= depth) {
            ret.push_back(root->val);
        }
        else {
            ret[depth] = max(ret[depth], root->val);
        }
        dfs(root->left, depth+1, ret); 
        dfs(root->right, depth+1, ret);
    }
};