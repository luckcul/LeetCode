class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = p.size(), len2 = s.size(); 
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= len1; i++) {
            for(int j = 0; j <= len2; j++) {
                if(j == 0) {
                    if(p[i-1] == '*' && (i-2 >= 0) && dp[i-2][j]) dp[i][j] = 1;
                }
                else {
                    if(p[i-1] == '.') {
                        if(dp[i-1][j-1]) dp[i][j] = 1;
                    }
                    else if(p[i-1] == '*') {
                        if(i-2 >= 0 && dp[i-2][j]) dp[i][j] = 1;
                        if(dp[i-1][j]){
                            if(p[i-2] == '.')  dp[i][j] = 3;
                            else  dp[i][j] = 2;
                        }
                        if(j > 1 && dp[i][j-1] == 2 && s[j-1] == s[j-2]) dp[i][j] = 2;
                        if(j > 1 && dp[i][j-1] == 3) dp[i][j] = 3;
                    }
                    else {
                        if(dp[i-1][j-1] && p[i-1] == s[j-1]) dp[i][j] = 1;
                    }
                }
            }
        }
        return dp[len1][len2] > 0;
    }
};