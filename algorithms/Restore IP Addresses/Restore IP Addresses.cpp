class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() < 1) return ret;
        dfs(s, 0, ret, "", 0);
        return ret;
    }
    void dfs(string &s, int index, vector<string> &ret, string now, int x) {
        
        if(x >= 4) {
            if(index >= s.size()) {
                ret.push_back(now.substr(1, now.size()-1));
            }
            return ;
        }
        int su = 0; 
        for(int i = index; i < s.size(); i++) {
            su *= 10; su += s[i] - '0';
            if(su > 255) break;
            dfs(s, i+1, ret, now + "." + s.substr(index, i-index+1), x+1);
            if(s[index] == '0') break;
        }
    }
};