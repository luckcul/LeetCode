class Solution {
public:
    int minInsertions(string s) {
        int len = s.size(); 
        vector<vector<int>> dp(len+1, vector<int>(len+1, 0)); 
        for(int i = 0; i <= len; i++) {
            for(int j = 0; j <=len; j++) {
                if(i>=j) dp[i][j] = 0; 
                else dp[i][j] = 11234567; 
            }
        }
        for(int l = 2; l <=len; l++) {
            for(int i = 0; i <= len-l; i++) {
                int j = i+l-1; 
                if(s[i] == s[j]) {
                    dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
                }
                else {
                    dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j-1])+1);
                }
                // cout<<i<<" "<<j<<" : "<<dp[i][j]<<endl;
            }
        }
        return dp[0][len-1];
    }
};