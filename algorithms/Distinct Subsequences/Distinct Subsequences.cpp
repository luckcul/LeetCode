class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.size(); 
        int len2 = t.size(); 
        vector<int> dp(len2+1, 0); 
        dp[0] = 1;
        for(int i = 1; i <= len1; i++) {
            for(int j = len2; j > 0; j--) {
                if(t[j-1] == s[i-1]) dp[j] += dp[j-1];
            }
        }
        return dp[len2];
    }
};