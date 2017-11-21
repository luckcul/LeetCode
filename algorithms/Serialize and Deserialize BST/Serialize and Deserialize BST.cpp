/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string intToString(int x) {
        string ret = "'";
        while(x) {
            ret += ('0' + (x % 10) ); 
            x /= 10;
        }
        return ret + "'";
    }
    void dfs(TreeNode *root, string &ret) {
        if(!root) {
            return ;
        }
        ret += intToString(root->val); 
        dfs(root->left, ret);
        dfs(root->right, ret);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = ""; 
        dfs(root, ret);
        // cout<<ret<<endl;
        return ret; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return parseString(data, index, (long long)(-1e10), (long long) 1e10);
    }
    TreeNode *parseString(string &data, int &index, long long min_, long long max_) {
            if(index >= data.size()) return NULL;
            int origin_index = index;
            int val = stringToInt(data, index);
            if(val < min_ || val > max_) {
                index = origin_index;
                return NULL;
            }
            TreeNode *ret = new TreeNode(val);
            index ++;
            long long min_left = min_, max_left = min(max_, (long long) val - 1);
            long long min_right = max(min_, (long long) val + 1), max_right = max_;
            ret->left = parseString(data, index, min_left, max_left);
            ret->right = parseString(data, index, min_right, max_right);
            return ret;
    }
    int stringToInt(string s, int &index) {
        int ret = 0; 
        int base = 1;
        index ++; 
        while(s[index] != '\'') {
            ret += base * (s[index] - '0');
            base *= 10;
            index ++;
        }
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));