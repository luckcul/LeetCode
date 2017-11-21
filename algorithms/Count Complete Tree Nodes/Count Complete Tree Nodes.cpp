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
    int get_depth(TreeNode *root) {
        if(!root) return 0; 
        return get_depth(root->left) + 1;
    }
    bool check(TreeNode *root, int s, int m) {
        if(m == 1) {
            if(root) return true;
            return false;
        }
        if(!root) return false;
        if(s <= m/2) {
            return check(root->left, s, m/2);
        }
        else {
            return check(root->right, s - m/2, m/2);
        }
    }
public:
    int countNodes(TreeNode* root) {
        int depth = get_depth(root);
        if(!depth) return depth;
        int l = 1;
        int r = (1<<(depth-1));
        int ret = l;
        while(l <= r) {
            int m = (l+r)>>1;
            if(check(root, m, 1<<(depth-1))){
                ret = m; 
                l = m+1;
            }
            else r = m-1;
        }
        return ret + (1<<(depth-1)) - 1;
    }
};