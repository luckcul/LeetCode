class Solution {
    struct node {
        long long mat[6][6] = {
            {1,1,1,0,0,0},
            {1,0,0,0,0,0},
            {0,1,0,0,0,0},
            {1,1,1,1,1,1},
            {0,0,0,1,0,0},
            {0,0,0,0,1,0}
        };
    }M;
    node mul(node x, node y) {
        node ret;
        memset(ret.mat, 0, sizeof(ret.mat));
        for(int i = 0; i < 6; i++) {
            for(int j = 0; j < 6; j++) {
                for(int k = 0; k < 6; k++) {
                    ret.mat[i][j] += x.mat[i][k] * y.mat[k][j];
                    ret.mat[i][j] %= (long long)(1e9+7);
                }
            }
        }
        return ret;
    }
    node power(node x, int y) {
        node ret;
        memset(ret.mat, 0, sizeof(ret.mat));
        for(int i = 0; i < 6; i++) ret.mat[i][i] = 1;
        while(y) {
            if(y&1) {
                ret = mul(ret, x);
            }
            y >>= 1;
            x = mul(x, x);
        }
        return ret;
    }
public:
    int checkRecord(int n) {
        // vector<vector<int>> dp(n+1, vector<int>(6, 0));
       node res = power(M, n);
       int ret = 0; 
       for(int i = 0; i < 6; i++) {
           ret += res.mat[i][0]; ret %= (int)(1e9 + 7);
       }
       return ret;
    }
};