class Solution {
    int dp[100005][6];
    int add(int x, int y) {
        int mod = 1e9+7;
        x %= mod; y %= mod;
        return (x+y) % mod;
    }
public:
    int checkRecord(int n) {
        // vector<vector<int>> dp(n+1, vector<int>(6, 0));
        dp[0][0] = 1;
        int mod = 1e9+7;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = add(dp[i-1][0], dp[i][0]);
            dp[i][0] = add(dp[i-1][1], dp[i][0]);
            dp[i][0] = add(dp[i-1][2], dp[i][0]);
            dp[i][1] = add(dp[i-1][0], dp[i][1]);
            dp[i][2] = add(dp[i-1][1], dp[i][2]);
            dp[i][3] = add(dp[i-1][3], dp[i][3]);
            dp[i][3] = add(dp[i-1][4], dp[i][3]);
            dp[i][3] = add(dp[i-1][5], dp[i][3]);
            dp[i][3] = add(dp[i][0], dp[i][3]); 
            dp[i][4] = add(dp[i-1][3], dp[i][4]);
            dp[i][5] = add(dp[i-1][4], dp[i][5]);
        }
        int ret = 0; 
        for(int i = 0; i < 6; i++) ret = add(ret, dp[n][i]);
        return ret;
    }
};