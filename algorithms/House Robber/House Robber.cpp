
class Solution {
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length+1, 2e9);
        if(length == 0) return 0;
        if(length == 1) return nums[0];
        dp[0] = 0; dp[1] = nums[0]; dp[2] = nums[1];
        for(int i = 2; i < length; i++) {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i-2] + nums[i]);
        }
        return max(dp[length], dp[length - 1]);
    }
};
