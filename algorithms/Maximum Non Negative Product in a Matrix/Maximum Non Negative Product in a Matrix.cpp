class Solution {
    long long dp_min[20][20]; 
    long long dp_max[20][20]; 
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        int is_zero = 0; 
        memset(dp_min, 0, sizeof(dp_min)); 
        memset(dp_max, 0, sizeof(dp_max)); 
        for(int i = 0; i <= n; i++) {
            dp_min[i][0] = dp_max[i][0] = 1; 
        }
        for(int j = 0; j < m; j++) {
            dp_min[0][j] = dp_max[0][j] = 1; 
        }
        
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) is_zero=1; 
                if(i==0 && j==0) {
                    dp_min[i+1][j+1] = dp_max[i+1][j+1] = grid[i][j]; 
                }
                else if(i == 0) {
                    dp_min[i+1][j+1] = 1LL*dp_min[i+1][j]*grid[i][j]; 
                    dp_min[i+1][j+1] = min(dp_min[i+1][j+1], 1LL*dp_max[i+1][j]*grid[i][j]); 
                    dp_max[i+1][j+1] = 1LL*dp_min[i+1][j]*grid[i][j]; 
                    dp_max[i+1][j+1] = max(dp_max[i+1][j+1], 1LL*dp_max[i+1][j]*grid[i][j]); 
                }
                else if(j == 0) {
                    dp_min[i+1][j+1] = 1LL*dp_min[i][j+1]*grid[i][j]; 
                    dp_min[i+1][j+1] = min(dp_min[i+1][j+1], 1LL*dp_max[i][j+1]*grid[i][j]); 
                    dp_max[i+1][j+1] = 1LL*dp_min[i][j+1]*grid[i][j]; 
                    dp_max[i+1][j+1] = max(dp_max[i+1][j+1], 1LL*dp_max[i][j+1]*grid[i][j]); 
                }
                else {
                dp_min[i+1][j+1] = 1LL*dp_min[i][j+1]*grid[i][j]; 
                dp_min[i+1][j+1] = min(dp_min[i+1][j+1], 1LL*dp_max[i][j+1]*grid[i][j]); 
                dp_min[i+1][j+1] = min(dp_min[i+1][j+1], 1LL*dp_min[i+1][j]*grid[i][j]); 
                dp_min[i+1][j+1] = min(dp_min[i+1][j+1], 1LL*dp_max[i+1][j]*grid[i][j]); 
                
                dp_max[i+1][j+1] = 1LL*dp_min[i][j+1]*grid[i][j]; 
                dp_max[i+1][j+1] = max(dp_max[i+1][j+1], 1LL*dp_max[i][j+1]*grid[i][j]); 
                dp_max[i+1][j+1] = max(dp_max[i+1][j+1], 1LL*dp_min[i+1][j]*grid[i][j]); 
                dp_max[i+1][j+1] = max(dp_max[i+1][j+1], 1LL*dp_max[i+1][j]*grid[i][j]); 
                }
                // cout<<dp_max[i+1][j+1]<<" "; 
            }
            // cout<<endl;
        }
        long long ret = dp_max[n][m]; 
        if(ret < 0 && is_zero) ret = 0; 
        return ret<0? -1 : (ret % (1000000007)); 
    }
};