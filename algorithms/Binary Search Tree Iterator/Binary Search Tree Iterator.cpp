/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
	vector<TreeNode *> iterators;
public:
    BSTIterator(TreeNode *root) {
        iterators.clear();
        if(root == NULL) return;
        iterators.push_back(root);
        while(root->left) {
        	root = root->left;
        	iterators.push_back(root);
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iterators.size() == 0 ? false : true;
    }

    /** @return the next smallest number */
    int next() {
        int val = iterators.back()->val;
        TreeNode *next = iterators.back()->right;
        iterators.pop_back();
        while(next) {
        	iterators.push_back(next);
        	next = next->left;
        }
        return val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
