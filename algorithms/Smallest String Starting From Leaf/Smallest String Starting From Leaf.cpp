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

    void sol(TreeNode* root, string &ans, string now, bool &flag) {
        now += 'a' + root->val; 
        // if(now < ans) ans = now; 
        if(root->left) sol(root->left, ans, now, flag); 
        if(root->right) sol(root->right, ans, now, flag); 
        string tmp(now); 
        if(!(root->left) && !(root->right)) {
            reverse(tmp.begin(), tmp.end());
            if(!flag) {
                flag = true; 
                ans = tmp;
            }
            else {
                if(tmp < ans) ans = tmp; 
            }
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) {
            return ""; 
        }
        string ans = "a";
        ans[0] += root->val; 
        bool flag = false;
        sol(root, ans, "", flag); 
        return ans; 
    }
};