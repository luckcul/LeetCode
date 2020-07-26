/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct node {
        int d[11]; 
    };
public:
    node dfs(TreeNode* root, int distance, int &res) {
        node ret; 
        memset(ret.d, 0, sizeof(ret.d)); 
        if(!root) {
            // ret.d[0]=1;
            return ret; 
        }
        if(!(root->left) && !(root->right)) {
            ret.d[0] = 1; 
            return ret; 
        }
        node ret_left = dfs(root->left, distance, res); 
        node ret_right = dfs(root->right, distance, res); 
        for(int i = 0; i <= distance; i++) {
            for(int j = 0; j <= distance; j++) {
                if(i+j+2>distance) continue;
                res += ret_left.d[i] * ret_right.d[j]; 
            }
        }
        for(int i = 1; i <= distance; i++) {
            ret.d[i] += ret_left.d[i-1]; 
            ret.d[i] += ret_right.d[i-1]; 
        }
        return ret; 
    }
    int countPairs(TreeNode* root, int distance) {
        int res = 0; 
        dfs(root, distance, res); 
        return res; 
    }
};