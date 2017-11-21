/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void getRight(TreeLinkNode *root, vector<TreeLinkNode *> &last, int depth) {
        if(!root) return ;
        if(depth > last.size()) last.push_back(NULL);
        root->next = last[depth - 1];
        last[depth - 1] = root;
        getRight(root->right, last, depth+1);
        getRight(root->left, last, depth+1);
    }
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode *> last;
        getRight(root, last, 1);
    }
};