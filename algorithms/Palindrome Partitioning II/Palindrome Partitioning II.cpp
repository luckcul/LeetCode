class Solution {
public:
    int minCut(string s) {
        int length = s.size(); 
        vector<int> dp(length, 0); 
        vector<vector<bool>> is_p(length, vector<bool>(length, false));
        for(int i = 0; i < length; i++) dp[i] = i;
        for(int i = 0; i < length; i++) {
            for(int j = i; j >= 0; j--) {
                if(s[i] == s[j] && (i-j < 2 || is_p[j+1][i-1])){
                    is_p[j][i] = true;
                    dp[i] = min(dp[i], j == 0 ? 0:dp[j-1]+1);
                }
            }
        }
        return dp[length-1];
    }
};