class Solution {
    struct Tree {
        char ch; 
        bool is_end; 
        Tree *p[30]; 
        Tree(char c, bool b) : ch(c), is_end(b){memset(p, 0, sizeof(p));}
    }; 
    
    void insert_tree(string &s, int idx, int length, Tree * root) {
        if(idx == length) {
            Tree *p; 
            if(root->p[26] == 0) {
                p = new Tree('/', true); 
                root->p[26] = p; 
            }
            else {
                p = root->p[26];
                p->is_end = true; 
            }
            return ; 
        }
        Tree *p; 
        int p_idx = (s[idx] == '/' ? 26:s[idx]-'a'); 
        if(root->p[p_idx] == 0) {
            p = new Tree(s[idx], false); 
            root->p[p_idx] = p; 
        }
        else {
            p = root->p[p_idx];    
        }
        
        insert_tree(s, idx+1, length, p); 
    }
    
    void dfs(Tree * root, string tmp, vector<string> & ret) {
        if(root == 0) {
            return ; 
        }
        // cout<<root->ch<<endl;
        if(root->ch == '/' && root->is_end == true) {
            ret.push_back(tmp); 
            return ; 
        }
        tmp += root->ch; 
        for(int i = 0; i <= 26; i++) {
            if(root->p[i] == 0) continue; 
            dfs(root->p[i], tmp, ret); 
        }
    }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Tree * root = new Tree('/', false); 
        int len = folder.size(); 
        for(int i = 0; i < len; i++) {
            int l = folder[i].size(); 
            insert_tree(folder[i], 1, l, root); 
        }
        vector<string> ret; 
        string tmp = "";
        dfs(root, tmp, ret); 
        return ret; 
    }
};