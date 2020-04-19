class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        long long dp[51][101][51]; 
        long long mod = 1000000007;
        memset(dp, 0, sizeof(dp)); 
        for(int i = 1; i <= m; i++) {
            dp[0][i][1] = 1; 
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= m; j++) {
                for(int ki = 1; ki <= k; ki++ ) {
                    dp[i][j][ki] += dp[i-1][j][ki]*(m-j+1); 
                    dp[i][j][ki] %= mod; 
                    for(int last_j = j+1; last_j <= m; last_j++) {
                        // int last_ki = (last_j )
                        dp[i][j][ki] += dp[i-1][last_j][ki-1]; 
                        dp[i][j][ki] %= mod; 
                    }
                }
            }
        }
        long long ret = 0; 
        for(int i = 1; i <= m; i++) {
            ret += dp[n-1][i][k]; 
            ret %= mod; 
        }
        return ret; 
    }
};