class Solution {
public:
    long long dp[55][5]; 
    int countVowelStrings(int n) {
        for(int i = 0; i < 5; i++) dp[1][i] = 1; 
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < 5; j ++) {
                int t = 0; 
                for(int k = 0; k<=j; k++) t += dp[i-1][k]; 
                dp[i][j] = t; 
            }
        }
        int ret = 0; 
        for(int i = 0; i< 5; i++)  ret += dp[n][i]; 
        return ret; 
    }
};