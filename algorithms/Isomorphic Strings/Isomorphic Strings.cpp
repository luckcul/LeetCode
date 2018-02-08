class Solution {
private:
    unordered_map<char,int> S, T;
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int cnt = 0; 
        for(int i = 0; i < s.size(); i++) {
            if(S[s[i]] != T[t[i]]) return false;
            S[s[i]] = T[t[i]] = ++cnt;
        }
        return true;
    }
};