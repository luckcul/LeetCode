class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[112][21][112]; 
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                for(int k = 0; k <=m; k++) {
                    dp[i][j][k] = 1e9; 
                }
            }
        }
        dp[0][0][0] = 0; 
        for(int i = 1; i <=m; i++) {
            cout<<i<<endl;
            for(int j = 1; j <= n; j++) {
                if(houses[i-1] != 0 && houses[i-1] != j) continue;  
                int cost_ = 0; 
                if(houses[i-1] == 0) {
                    cost_ = cost[i-1][j-1]; 
                }
                for(int k = 1; k <= target; k++) {
                    
                    if(i == 1) {
                        dp[i][j][k] = (k == 1 ? cost_:1e9); 
                    }
                    else {
                        for(int last_j = 1; last_j <= n; last_j++) {
                            int last_k; 
                            if(last_j == j) last_k = k; 
                            else last_k = k-1; 
                            int last_v = dp[i-1][last_j][last_k]; 
                            dp[i][j][k] = min(dp[i][j][k], last_v+cost_); 
                        }
                    }
                    // cout<<i<<","<<j<<","<<k<<":"<<dp[i][j][k]<<endl;
                }
            }
        }
        int ret = 1e9; 
        for(int j = 1; j <= n; j++) {
            ret = min(ret, dp[m][j][target]); 
        }
        return ret < 1e9 ? ret:-1; 
    }
};