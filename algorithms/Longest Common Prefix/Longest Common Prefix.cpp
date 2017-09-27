class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string ret = "";
        int minLen = 1e9;
        for(int i = 0; i < strs.size(); i++) {
            minLen = min(minLen, (int)strs[i].size());
        }
        for(int i = 0; i < minLen; i++) {
            bool ok = true;
            for(int j = 1; j < strs.size(); j++) {
                if(strs[j][i] != strs[j-1][i] ) {
                    ok = false;
                    break;
                }
            }
            if(ok) ret += strs[0][i];
            else break;
        }
        return ret;
    }
};