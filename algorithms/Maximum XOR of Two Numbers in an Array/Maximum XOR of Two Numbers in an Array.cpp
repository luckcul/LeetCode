class Solution {
    struct Trie{
        Trie *next[2];
        Trie(){
            next[0] = next[1] = NULL;
        };
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *root = new Trie();
        for(int i = 0; i < nums.size(); i++) {
            insert(root, nums[i]); 
        }
        int ret = -1; 
        for(int i = 0; i < nums.size(); i++) {
            ret = max(ret, find_max(root, nums[i])); 
        }
        return ret; 
    }
    void insert(Trie *root, int num) {
        for(int i = 30; i >= 0; i--) {
            int val = (num >> i)&1; 
            if(!root->next[val]) {
                root->next[val] = new Trie();
            }
            root = root->next[val]; 
        }
    }
    int find_max(Trie *root, int num) {
        int ret = 0; 
        for(int i = 30; i >= 0; i--) {
            int val = (num>>i)&1; 
            val ^= 1; 
            ret <<= 1; 
            if(root->next[val]) {
                ret += val; 
                root = root->next[val]; 
            }
            else {
                ret += val^1; 
                root= root->next[val^1]; 
            }
        }
        return ret^num; 
    }
};