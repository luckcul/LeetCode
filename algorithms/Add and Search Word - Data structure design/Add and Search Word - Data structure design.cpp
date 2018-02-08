class WordDictionary {
private:
    struct Trie {
        char val;
        bool is_end;
        Trie *next[26];
        Trie(char ch):val(ch), is_end(false){
            memset(next, 0, sizeof(next));
        }
    };
    Trie *root;
    bool search_from(string &word, Trie *p, int index) {
        if(!p) return false;
        if(index >= word.size()){
            if(p->is_end) return true;
            return false;
        }
        if(word[index] == '.') {
            for(int i = 0; i <= 'z'-'a'; i++) {
                if(p->next[i]){
                    bool flag_i = search_from(word, p->next[i], index+1);
                    if(flag_i) return true;
                }
            }
            return false;
        }
        else {
            return search_from(word, p->next[word[index] - 'a'], index+1);
        }
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        this->root = new Trie(0);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie *p = root;
        for(int i = 0; i < word.size(); i++) {
            int val = word[i] - 'a';
            if(!p->next[val]) {
                p->next[val] = new Trie(word[i]);
            }
            p = p->next[val];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        if(!root) return false;
        return search_from(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */