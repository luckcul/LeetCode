class Solution {
    void maxValue(vector<int>& nums, vector<int>& dp) {
        int length = nums.size();
        for(int i = 2; i < length; i++) {
            dp[i+1] = max(dp[i-1] + nums[i], dp[i-2] + nums[i]);
        }

    }
public:
    int rob(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 0;
        if(length == 1) return nums[0];
        vector<int> dp(length+1, 2e9);
        dp[0] = 0; dp[1] = 0; dp[2] = nums[1];
        maxValue(nums, dp);
        int ret1 = max(dp[length], dp[length-1]);
        dp.clear();
        dp[0] = 0; dp[1] = nums[0]; dp[2] = nums[1];
        maxValue(nums, dp);
        int ret2 = max(dp[length-1], dp[length-2]);
        return max(ret1, ret2);
    }
};