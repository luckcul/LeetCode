class Solution {
public:
    bool cmp(string a, string b) {
        int la = a.size(); 
        int lb = b.size(); 
        if(la > lb) return false; 
        for(int i = 0; i+la-1 < lb; i++) {
            for(int j = 0; j < la; j++) {
                if(a[j] != b[i+j]) break; 
                if(j == la-1) return true; 
            }
        }
        return false; 
    }
    vector<string> stringMatching(vector<string>& words) {
        cout<<cmp("as", "mass")<<endl;
        vector<string> ret; 
        int len = words.size(); 
        for(int i = 0; i < len; i++) {
            bool f = false; 
            for(int j = 0; j < len; j++) {
                if(i == j) continue; 
                f = cmp(words[i], words[j]); 
                if(f) break; 
                
            }
            if(f) ret.push_back(words[i]); 
        }
        return ret; 
    }
};