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
    struct node {
        TreeNode *p;
        int level;
        node(TreeNode *p_, int le):p(p_), level(le){}
    };
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<node> Q;
        vector<vector<int>> ret;
        if(!root) return ret;
        Q.push(node(root, 0));
        int last_level = -1;
        while(!Q.empty()) {
            node now = Q.front();
            if(now.level == last_level) {
                ret[ret.size()-1].push_back(now.p->val);
            }
            else {
                ret.push_back(vector<int>());
                ret[ret.size()-1].push_back(now.p->val);
            }
            last_level = now.level;
            Q.pop();
            if(now.p->left) Q.push(node(now.p->left, now.level+1));
            if(now.p->right) Q.push(node(now.p->right, now.level+1));
        }
        return ret;
    }
};