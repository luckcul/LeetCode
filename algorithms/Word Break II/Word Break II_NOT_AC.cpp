class Solution {
    struct node {
        bool vis;
        node *next[26];
        node(bool v){
            vis = v;memset(next, 0, sizeof(next));
        }
    };
    node *root;
    void insert(string s) {
        node *p = root;
        for(int i = 0; i < s.size(); i++) {
            int ch = s[i] - 'a';
            if(p->next[ch]) {
                p = p->next[ch];
            }
            else {
                p->next[ch] = new node(false);
                p = p->next[ch];
            }
        }
        p->vis = true;
    }
    void dfs(string s, int index, string break_words, vector<string> &ret) {
        int len = s.size(); 
        if(index >= len) {
            ret.push_back(break_words.substr(0, break_words.size() - 1));
            return ;
        }
        node *p = root;
        for(int i = index; i < len; i++) {
            int ch = s[i] - 'a';
            if(p->next[ch]){
                p = p->next[ch];
                if(p->vis){
                    string new_str = break_words + s.substr(index, i-index+1);
                    new_str += " ";
                    dfs(s, i+1, new_str, ret);
                }
            }
            else {
                break;
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new node(false);
        for(int i = 0; i < wordDict.size(); i++) {
            insert(wordDict[i]);
        }
        vector<string> ret; 

        dfs(s, 0, "", ret); 
        return ret;
    }
};