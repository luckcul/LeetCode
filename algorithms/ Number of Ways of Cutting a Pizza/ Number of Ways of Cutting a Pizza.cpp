class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        long long dp[51][51][11]; 
        long long mod = 1000000007;
        memset(dp, 0, sizeof(dp)); 
        dp[0][0][0] = 1; 
        int n = pizza.size(); 
        int m = pizza[0].size(); 
        vector<vector<int>> piz; 
        for(int i = 0; i < n; i++) {
            vector<int> r; 
            for(int j = 0; j < m; j++) {
                r.push_back(pizza[i][j] == '.' ? 0:1); 
            }
            piz.push_back(r); 
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int z = 0; z < k; z++) {
                    if(dp[i][j][z] == 0) continue; 
                    vector<int> col(m+1, 0); 
                    vector<int> row(n+1, 0); 
                    int temp_s = 0; 
                    for(int cut_i = i+1; cut_i < n; cut_i++){
                        for(int sj = j; sj < m; sj++) {
                            temp_s += piz[cut_i-1][sj]; 
                        }
                        if(temp_s > 0) {
                            dp[cut_i][j][z+1] += dp[i][j][z]; 
                            dp[cut_i][j][z+1] %= mod; 
                        }
                    }
                    temp_s = 0; 
                    for(int cut_j = j+1; cut_j < m; cut_j++) {
                        for(int si = i; si < n; si++) {
                            temp_s += piz[si][cut_j-1]; 
                        }
                        if(temp_s > 0) {
                            dp[i][cut_j][z+1] += dp[i][j][z]; 
                            dp[i][cut_j][z+1] %= mod; 
                        }
                    }
                }
            }
        }
        long long ret = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(dp[i][j][k-1] == 0) continue; 
                int s = 0; 
                for(int si = i; si < n; si++) {
                    for(int sj = j; sj < m; sj++) {
                        s += piz[si][sj];
                    }
                }
                if(s > 0) {
                    ret += dp[i][j][k-1]; 
                    ret %= mod; 
                }
            }
        }
        return ret; 
    }
};