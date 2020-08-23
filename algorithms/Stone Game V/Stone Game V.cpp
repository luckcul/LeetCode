class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int dp[512][512]; 
        memset(dp, 0, sizeof(dp)); 
        int n = stoneValue.size(); 
        int su[512]; 
        su[0] = 0; 
        for(int i = 0; i < n; i++) {
            su[i+1]=su[i]+stoneValue[i]; 
        }
        for(int window = 2; window <= n; window++) {
            for(int i= 1; i+window-1<=n; i++) {
                int j=i+window-1; 
                for(int k = i; k < j; k++) {
                    int left_value = su[k] - su[i-1]; 
                    int right_value = su[j] - su[k]; 
                    if(left_value>right_value) {
                        dp[i][j] = max(dp[i][j], right_value + dp[k+1][j]); 
                    }
                    else if(left_value<right_value) {
                        dp[i][j] = max(dp[i][j], left_value + dp[i][k]); 
                    }
                    else {
                        dp[i][j] = max(dp[i][j], max(right_value+dp[k+1][j], left_value+dp[i][k]));
                    }
                }
            }
        }
        return dp[1][n]; 
    }
};