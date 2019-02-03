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
    void sol(TreeNode *root, vector<vector<pair<int, int>>> &ret, int x, int y) {
        ret[x].push_back(make_pair(y, root->val)); 
        if(root->left) sol(root->left, ret, x-1, y+1); 
        if(root->right) sol(root->right, ret, x+1,  y+1); 
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int, int>>> ret1(3000,  vector<pair<int, int>>());
        int init_x = 1500; 
        int init_y = 0; 
        sol(root, ret1, init_x, init_y); 
        vector<vector<int>> ret; 
        for(int i = 0; i < 3000; i++) {
            int len = ret1[i].size(); 
            if(!len) continue; 
            sort(ret1[i].begin(), ret1[i].end()); 
            vector<int> v; 
            for(int j = 0; j < len; j++) {
                v.push_back(ret1[i][j].second);
            }
            ret.push_back(v); 
        }
        return ret; 
    }
};