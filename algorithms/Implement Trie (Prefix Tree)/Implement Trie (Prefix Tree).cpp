class Trie {
    struct node {
        node *next[26];
        bool vis;
        node(bool end) {
            vis = end; memset(next, NULL, sizeof(next));
        }
    };
    node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new node(false);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node *now_p = root;
        for(int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            if(now_p->next[ch]) {
                now_p = now_p->next[ch];
            }
            else {
                now_p->next[ch] = new node(false);
                now_p = now_p->next[ch];
            }
            if(i == word.size() - 1) now_p->vis = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node *now_p = root;
        for(int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a';
            if(now_p) {
                now_p = now_p->next[ch];
            }
            else {
                return false;
            }
        }
        return now_p != NULL && now_p->vis;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node *now_p = root;
        for(int i = 0; i < prefix.size(); i++) {
            int ch = prefix[i] - 'a';
            if(now_p){
                now_p = now_p->next[ch];
            }
            else {
                return false;
            }
        }
        return now_p != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */