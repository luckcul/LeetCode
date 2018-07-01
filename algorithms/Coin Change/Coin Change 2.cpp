class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0); 
        dp[0] = 1; 
        int length = coins.size(); 
        for(int i = 0; i < length; i++) {
            int coin = coins[i]; 
            for(int j = 1; j <= amount; j++) {
                if(j - coin >= 0) {
                    dp[j] += dp[j-coin]; 
                }
            }
        }
        return dp[amount]; 
    }
};