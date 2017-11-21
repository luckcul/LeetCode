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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s) return false;
        if(isEqual(s, t)) {
            return true;
        }
        if(isSubtree(s->left, t)) return true;
        if(isSubtree(s->right, t)) return true;
        return false;
    }
    bool isEqual(TreeNode* s, TreeNode*t) {
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val != t->val) return false;
        bool res1 = isEqual(s->left, t->left);
        bool res2 = isEqual(s->right, t->right);
        return res1 && res2;
    }
};