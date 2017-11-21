class Solution {
    unordered_map<string, vector<string>> M;
    vector<string> combine(string prefix, vector<string> remains){
        for(int i = 0; i < remains.size(); i++) {
            remains[i] = prefix + " " + remains[i];
        }
        return remains;
    }
    vector<string> breaks(string s, unordered_set<string> &S) {
        if(M.find(s) != M.end()) return M[s];
        vector<string> ret;
        if(S.find(s) != S.end()) {
            ret.push_back(s);
        }
        for(int i = 1; i < s.size(); i++) {
            string prefix = s.substr(0, i);
            if(S.find(prefix) != S.end()){
                string remain = s.substr(i, s.size() - i);
                vector<string> ret_ = combine(prefix, breaks(remain, S));
                ret.insert(ret.end(), ret_.begin(), ret_.end());
            }
        }
        M[s] = ret;
        return ret;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S;
        for(int i = 0; i < wordDict.size(); i++) S.insert(wordDict[i]);
        return breaks(s, S);
    }
};