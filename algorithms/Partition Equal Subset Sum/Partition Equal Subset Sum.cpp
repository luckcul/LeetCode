class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int length = nums.size(); 
        int s = 0; 
        for(int i = 0; i < length; i++) s += nums[i];
        if(s & 1) return false;
        vector<int> dp(s/2+1, 0);
        dp[0] = 1;
        for(int i = 0; i < length; i++) {
            for(int j = s/2; j >= 0; j--) {
                if(j - nums[i] >= 0) dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[s/2];
    }
};