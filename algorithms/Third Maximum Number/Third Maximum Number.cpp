class Solution {
public:
    int thirdMax(vector<int>& nums) {
        bool vis[3];
        int val[3]; 
        memset(vis, 0, sizeof(vis)); 
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 3; j++) {
                if(!vis[j] || nums[i] > val[j]) {
                    for(int k = 2; k > j; k--) {
                        val[k] = val[k-1];  vis[k] = vis[k-1];
                    }
                    vis[j] = true; val[j] = nums[i]; 
                    break;
                } 
                if(vis[j] && nums[i] == val[j]) break;
            }
        }
        if(vis[2]) return val[2]; 
        return val[0]; 
    }
};