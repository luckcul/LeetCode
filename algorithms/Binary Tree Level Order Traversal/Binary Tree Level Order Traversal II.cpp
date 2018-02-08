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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<TreeNode *>> ret; 
        if(!root) return vector<vector<int>>();
        ret.push_back(vector<TreeNode *>(1, root));
        int index = 0;
        while(true) {
            vector<TreeNode *> tv; 
            for(int i = 0; i < ret[index].size(); i++) {
                auto p = ret[index][i];
                if(p->left) tv.push_back(p->left); 
                if(p->right) tv.push_back(p->right);
            }
            if(tv.size() <= 0) break;
            index ++; 
            ret.push_back(tv);
        }
        vector<vector<int>> re; 
        for(int i = index; i >= 0; i--) {
            vector<int> tv; 
            for(int j = 0; j < ret[i].size(); j++) tv.push_back(ret[i][j]->val);
            re.push_back(tv);
        }
        return re;
    }
};