class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end()); 
        int len = cuts.size(); 
        long long dp[123][123]; 
        memset(dp, 0, sizeof(dp)); 
        cuts.insert(cuts.begin(), 0); 
        cuts.push_back(n); 
        for(int i = 1; i < cuts.size(); i++) {
            for(int j = i-1; j >=0; j--) {
                if(j+1<i) {
                    dp[j][i] = 1e10; 
                    for(int k = j+1; k < i; k++) {
                        dp[j][i] = min(dp[j][i], dp[j][k] + dp[k][i]); 
                    }
                }
                dp[j][i] += cuts[i] - cuts[j]; 
                // cout<<j<<", "<<i<<": "<<dp[j][i]<<endl;
            }
        }
        return dp[0][cuts.size()-1]-n;
    }
};