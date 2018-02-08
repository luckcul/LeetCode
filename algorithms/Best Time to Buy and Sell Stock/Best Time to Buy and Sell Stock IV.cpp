class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp1[i][j] = max(dp2[i-1][j-1] + diff, dp1[i-1][j] + diff)
        // dp2[i][j] = max(dp2[i-1][j], dp1[i][j])
        if(k >= prices.size()) {
            int ret = 0; 
            for(int i = 1; i < prices.size(); i++) {
                if(prices[i] > prices[i-1]) ret += prices[i] - prices[i-1];
            }
            return ret;
        }
        vector<int> dp1 = vector<int>(k+1, 0);
        vector<int> dp2 = vector<int>(k+1, 0);
        for(int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            for(int j = k; j >= 1; j--) {
                dp1[j] = max(dp2[j-1] + max(0, diff), dp1[j] + diff);
                dp2[j] = max(dp2[j], dp1[j]);
                // printf(" (%d %d) ", dp1[j], dp2[j]);
            }
            // cout<<endl;
        }
        return dp2[k];
    }
};