class Solution {
public:
    int countArrangement(int N) {
        vector<int> dp(40000, 0);
        dp[0] = 1;
        for(int i = 1; i < (1<<N); i++) {
            int total = 0; 
            int temp = i;
            while(temp) total += temp & 1, temp >>= 1;
            for(int j = 0; j < N; j++) {
                if((i & (1<<j) && (total % (j+1) == 0 || (j + 1) % total == 0))) {
                    dp[i] += dp[i ^ (1<<j)];
                }
            }
        }
        return dp[(1<<N)-1];
    }
};