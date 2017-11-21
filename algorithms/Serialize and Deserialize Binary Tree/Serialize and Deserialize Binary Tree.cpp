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
            ret += '#';
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
        return parseString(data, index);
    }
    TreeNode *parseString(string &data, int &index) {
        char ch = data[index];
        if(ch == '#') {
            index ++;
            return NULL;
        }
        else{
            TreeNode *ret = new TreeNode(stringToInt(data, index));
            index ++;
            ret->left = parseString(data, index);
            ret->right = parseString(data, index);
            return ret;
        }
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