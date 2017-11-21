class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size(); 
        int len2 = p.size();
        vector<vector<bool>> dp(len2 + 1, vector<bool>(len1+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len2; i++) {
            for(int j = 0; j <= len1; j++) {
                if(j == 0) {
                    if(dp[i-1][j] && p[i-1] == '*') dp[i][j] = true;
                }
                else {
                    if(p[i-1] == '*') dp[i][j] = (dp[i-1][j] || dp[i][j-1] || dp[i-1][j-1]);
                    else if(p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = (dp[i-1][j-1] && p[i-1] == s[j-1]);
                }
            }
        }
        return dp[len2][len1];
    }
};