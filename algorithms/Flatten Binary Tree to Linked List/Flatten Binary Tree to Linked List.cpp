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
    void flatten(TreeNode* root) {
        dfs(root);
    }

    pair<TreeNode *, TreeNode *> dfs(TreeNode *root){
        if(!root) {
            return make_pair((TreeNode *) NULL, (TreeNode *) NULL);
        }
        pair<TreeNode *, TreeNode *> ret;
        ret.first = root;
        auto ret1 = dfs(root->left);
        auto ret2 = dfs(root->right);
        if(ret1.first){
            root->right = ret1.first;
            ret.second = ret1.second;
        }
        if(ret2.first) {
            if(ret.second) {
                ret.second->right = ret2.first;
                ret.second = ret2.second;
            }
            else {
                root->right = ret2.first;
                ret.second = ret2.second;
            }
        }
        root->left = NULL;
        if(!ret.second) ret.second = root;
        return ret;
    }
};