class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> S;
        for(int i = 0; i < wordDict.size(); i++) {
            S.insert(wordDict[i]);
        }
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i-1; j >= 0; j --) {
                if(dp[j]) {
                    string sTemp = s.substr(j, i - j);
                    if(S.find(sTemp) != S.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};