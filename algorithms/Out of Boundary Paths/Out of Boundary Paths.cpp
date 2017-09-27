class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int mod = 1e9 + 7;
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int dp[55][55][55];
        memset(dp, 0, sizeof(dp));
        dp[0][i][j] = 1;
        for(int k = 1; k < N; k++) {
            for(int x = 0; x < m; x ++) {
                for(int y = 0; y < n; y++) {
                    for(int ii = 0; ii < 4; ii ++){
                        int nx = x + dir[ii][0];
                        int ny = y + dir[ii][1];
                        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        dp[k][x][y] += dp[k-1][nx][ny];
                        dp[k][x][y] %= mod;
                    }
                }
            }
        }
        int total = 0;
        for(int k = 0; k < N; k++) {
            for(int x = 0; x < m; x ++) {
                total += dp[k][x][0], total %= mod;
                total += dp[k][x][n-1], total %= mod;
            }
            for(int y = 0; y < n; y ++) {
                total += dp[k][0][y], total %= mod;
                total += dp[k][m-1][y], total %= mod;
            }
        }
        return total;
    }
};