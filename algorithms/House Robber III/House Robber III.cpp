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
    vector<int> dfs(TreeNode* p) {
        vector<int> ret(2, 0);
        if(!p) return ret;
        vector<int> ret1 = dfs(p->left);
        vector<int> ret2 = dfs(p->right);
        ret[0] = ret1[1] + ret2[1] + p->val;
        ret[1] = max(ret1[0], ret1[1]) + max(ret2[0], ret2[1]);
        return ret;
    }
public:
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};