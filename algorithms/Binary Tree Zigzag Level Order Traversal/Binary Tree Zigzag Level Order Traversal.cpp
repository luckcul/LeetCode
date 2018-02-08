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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        stack<TreeNode *> S[2];
        int now_index = 0; 
        S[now_index].push(root);
        while(!S[now_index].empty()) {
            int next_index = now_index ^ 1;
            vector<int> v; 
            while(!S[now_index].empty()) {
                auto node = S[now_index].top();
                v.push_back(node->val);
                S[now_index].pop();
                if(now_index) {
                    if(node->right) S[next_index].push(node->right); 
                    if(node->left) S[next_index].push(node->left);
                }
                else {
                    if(node->left) S[next_index].push(node->left); 
                    if(node->right) S[next_index].push(node->right);
                }
            }
            ret.push_back(v);
            now_index = next_index;
        }
        return ret;
    }
};