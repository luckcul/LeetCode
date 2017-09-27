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
     pair<int, int> dfs(TreeNode *root, int depth) {
         pair<int, int> ret = make_pair(depth, root->val);
         if(root->left) {
            pair<int, int> ret1 = dfs(root->left, depth + 1);
            if(ret1.first > ret.first) ret = ret1;
         }
         if(root->right) {
             pair<int, int> ret2 = dfs(root->right, depth + 1);
             if(ret2.first > ret.first) ret = ret2;
         }
         return ret;
     }
public:
    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> ret = dfs(root, 1);
        return ret.second;
    }
};