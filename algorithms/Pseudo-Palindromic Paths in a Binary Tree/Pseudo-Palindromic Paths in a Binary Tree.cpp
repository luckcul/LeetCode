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
public:
    void dfs(TreeNode* root, int & ret, vector<int> & nums) {
        if(!root) return ; 
        int val = root->val; 
        nums[val] ++; 
        dfs(root->left, ret, nums); 
        dfs(root->right, ret, nums); 
        if(!root->left && !root->right) {
            int odd = 0; 
            int even = 0; 
            int tot = 0; 
            for(int i = 0; i <= 9; i++) {
                tot += nums[i]; 
                if(nums[i] & 1) odd++; 
                else even++; 
            }
            if(tot & 1) {
                if(odd == 1) ret++; 
            }
            else {
                if(odd == 0) ret++; 
            }
        }
        
        nums[val]--; 
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ret = 0; 
        vector<int> nums(10, 0); 
        dfs(root, ret, nums); 
        return ret; 
    }
};