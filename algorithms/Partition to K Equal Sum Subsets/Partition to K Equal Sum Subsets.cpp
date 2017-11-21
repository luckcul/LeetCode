class Solution {
    void setVis(vector<bool> &vis, vector<int> &path, int ave, int length, vector<int> &nums) {
        int nowV = ave; 
        while(path[nowV] != -1) {
            int step = path[nowV];
            // cout<<nowV<<" "<<step<<endl;
            vis[step] = true;
            nowV -= nums[step];
        }
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int length = nums.size(); 
        int s = 0; 
        for(int i = 0; i < length; i++) {
            s += nums[i];
        }
        if(s % k) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        int ave = s / k;
        vector<bool> vis(length, false);
        for(int ti = 1; ti <= k ;ti ++) {
            vector<int> dp(ave + 1, 0); 
            vector<int> path(ave + 1, -1);
            dp[0] = 1;
            for(int i = 0; i < length; i++) {
                if(vis[i]) continue;
                for(int j = ave; j >= 0; j --) {
                    if(dp[j]) continue;
                    if(j - nums[i] >= 0){
                        if(dp[j - nums[i]]) {
                            dp[j] = 1;
                            path[j] = i;
                        }
                    }
                }
            }
            if(dp[ave] == 0) return false;
            // cout<<1<<endl;
            setVis(vis, path, ave, length, nums);
            // cout<<2<<endl;
        }
        return true;
    }
};