
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
	void dfs(vector<int> &ret, TreeNode *p){
		if(p->left) dfs(ret, p->left);
		ret.push_back(p->val);
		if(p->right) dfs(ret, p->right);
	}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root) return ret;
        dfs(ret, root);
        return ret;
    }
};
