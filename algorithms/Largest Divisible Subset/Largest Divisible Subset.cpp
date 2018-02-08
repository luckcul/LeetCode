class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();  
        if(len < 1) return vector<int>();
        vector<int> path = vector<int>(len, -1); 
        vector<int> dp = vector<int>(len, 1); 
        dp[0] = 1; 
        int max_index = -1, max_val = -1; 
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[j]+1 > dp[i]) {
                    dp[i] = dp[j] + 1; 
                    path[i] = j;
                }
            }
            if(dp[i] > max_val) {
                max_val = dp[i]; max_index = i;
            }
        }
        vector<int> ret; 
        while(max_index != -1) {
            ret.push_back(nums[max_index]); max_index = path[max_index];
        }
        return ret; 
    }
};