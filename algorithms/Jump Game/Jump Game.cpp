class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            int steps = nums[i];
            if(dp[i] == 0) continue;
            for(int j = 1; j <= nums[i]; j++) {
                if(i+j < nums.size()) dp[i+j] = 1;
            }
        }
        return dp[nums.size()-1] == 1;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reached = 0;
        for(int i = 0; i <= min(reached, int(nums.size()) -1); i++) {
            reached = max(reached, i+nums[i]);
        }
        return reached >= nums.size()-1;
    }
};