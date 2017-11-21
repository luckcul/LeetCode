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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        return generate(nums, 0, size - 1, 0);
    }
    TreeNode *generate(vector<int> &nums, int l, int r, int status) {
        int len = r - l + 1, m;
        if(len == 1) return (new TreeNode(nums[l]));
        if(len < 1) return NULL;
        m = l + len/2;
        if(!(len&1)) {
            if(status) m--;
            status ^= 1;
        }
        TreeNode *root = new TreeNode(nums[m]);
        root->left = generate(nums, l, m-1, status);
        root->right = generate(nums, m+1, r, status);
        return root;
    }
};