class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> dp(length + 1, 0);
        int ret = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < length; i++) {
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            ret = max(ret, dp[i]);
        } 
        return ret;
    }
};