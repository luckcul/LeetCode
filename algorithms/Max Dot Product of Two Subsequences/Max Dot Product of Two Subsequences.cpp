class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(); 
        int len2 = nums2.size(); 
        vector<vector<int> > dp(len1+1, vector<int>(len2+1, -1e7)); 
        dp[0][0] = 0; 
        for(int i = 1; i <= len1; i++) {
            for(int j = 1; j <= len2; j++) {
                // dp[i][j] = max(dp[i][j], ( ( (i<=1 || j <=1) ? 0:dp[i-1][j-1]) ) + nums1[i-1] * nums2[j-1] ); 
                dp[i][j] = max(dp[i][j],  (dp[i-1][j-1] < 0 ? 0: dp[i-1][j-1]) + nums1[i-1] * nums2[j-1] ); 
                dp[i][j] = max(dp[i][j], dp[i-1][j]); 
                dp[i][j] = max(dp[i][j], dp[i][j-1]); 
            }
        }
        // for(int i = 1; i <= len1; i++) {
        //     for(int j = 1; j <=len2; j++) {
        //         cout<<dp[i][j]<<" "; 
        //     }
        //     cout<<endl;
        // }
        return dp[len1][len2]; 
    }
};