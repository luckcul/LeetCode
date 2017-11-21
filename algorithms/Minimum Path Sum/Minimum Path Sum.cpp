class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(); 
        if(!n) return 0; 
        int m = grid[0].size(); 
        if(!m) return 0; 
        vector<vector<int>> dp(2, vector<int>(m, 0));
        int now = 0; 
        dp[now][0] = grid[0][0];
        for(int i = 1; i < m; i++) dp[now][i] = dp[now][i-1] + grid[0][i];
        for(int i = 1; i < n; i++) {
            int next = now ^ 1; 
            // memset(dp[next], 0, sizeof(dp[next]));
            fill(dp[next].begin(), dp[next].end(), 0);
            for(int j = 0; j < m; j++) {
                if(j == 0) dp[next][j] = dp[now][j] + grid[i][0];
                else dp[next][j] = min(dp[now][j] + grid[i][j], dp[next][j-1] + grid[i][j]);
            }
            now = next;
        }
        return dp[now][m-1];
    }
};