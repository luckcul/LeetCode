class Solution {
    int dp[15][5000]; 
    int sum[5000]; 
public: 
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0]=0; 
        int n = cost.size(); 
        int m = cost[0].size(); 
        int lim = (1<<m)-1; 
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= lim; j++) {
                sum[j] = 0; 
                for(int k=0; k <m; k++) {
                    if((j>>k)&1) sum[j] += cost[i-1][k]; 
                }
            }
            
             for (int j = 0; j <= lim; ++j){
                for(int k = 0; k < m; k++) {
                    if((j>>k) & 1 ==0) continue; 
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + cost[i-1][k]); 
                } 
                 int jj = (lim^j); 
                 for(int u = jj; u>0; u = (u-1)&jj) {
                     dp[i][j|u] = min(dp[i][j|u], dp[i-1][j] + sum[u]); 
                 }

            }
            
        }
        
        return dp[n][lim]; 
    }
};