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
    vector<TreeNode *> generate(int min_, int max_) {
        vector<TreeNode *> ret; 
        if(min_ > max_) {
            ret.push_back(NULL);
            return ret;
        }
        for(int i = min_; i <= max_; i++) {
            auto ret_left = generate(min_, i-1); 
            auto ret_right = generate(i+1, max_);
            for(int i_left = 0; i_left < ret_left.size(); i_left++) {
                for(int i_right = 0; i_right < ret_right.size(); i_right++) {
                    auto head = new TreeNode(i);
                    head->right = ret_right[i_right];
                    head->left = ret_left[i_left];
                    ret.push_back(head);
                }
            }
        }
        return ret;
    }
public:
    vector<TreeNode*> generateTrees(int n) {        
        vector<TreeNode *> ret ;
        if(n < 1) return ret;
        ret = generate(1, n);   
        return ret;
    }
};