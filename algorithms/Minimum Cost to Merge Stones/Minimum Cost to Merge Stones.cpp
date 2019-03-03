class Solution { 
public:
    int mergeStones(vector<int>& stones, int K) {
        int len = stones.size(); 
        int inf = 112345678; 
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(len+1, vector<int>(len+1, inf))); 
        for(int i = 0; i <= len; i++) dp[i][i][1] = 0; 
        vector<int> prefix_sum(len+1, 0); 
        for(int i = 1; i <= len; i++) {
            prefix_sum[i] = prefix_sum[i-1] + stones[i-1]; 
        }
        for(int s = 1; s <= len; s++) {
            for(int i = 1; i <= len-s+1; i++) {
                int j = i+s-1; 
                for(int size = 2; size <= s; size++) {
                    for(int k = i; k < j; k++) {
                        dp[i][j][size] = min(dp[i][j][size], dp[i][k][size-1] + dp[k+1][j][1]);
                    }
                    dp[i][j][1] = min(dp[i][j][1], dp[i][j][K] + prefix_sum[j] - prefix_sum[i-1]);
                }
            }
        }
        return dp[1][len][1] >= inf? -1:dp[1][len][1];
    }
};