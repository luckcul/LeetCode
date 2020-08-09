class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int len = nums.size(); 
        unordered_map<int, vector<int> > M; 
        vector<int> s; 
        int last = 0; 
        s.push_back(0); 
        for(int i = 0; i < len; i++) {
            // s[i+1] = s[i] + nums[i]; 
            s.push_back(nums[i] + last); 
            last += nums[i]; 
        }
        vector<int> p(1, 0); 
        M[0] = p; 
        vector<int> dp(len+1, 0); 
        // cout<<"0k"<<endl;
        for(int i = 0; i < len; i++) {
            int cur_s = s[i+1]; 
            int need_last_s = cur_s-target; 
            dp[i+1] = dp[i]; 
            unordered_map<int, vector<int> >::iterator it = M.find(need_last_s); 
            // cout<<"ok2"<<endl;
            if(it != M.end()) {
                vector<int> pi = M[need_last_s]; 
                for(int j = 0; j < pi.size(); j++) {
                    int last_idx = pi[j]; 
                    dp[i+1] = max(dp[i+1], dp[last_idx]+1); 
                }
            }
            if(M.find(cur_s) == M.end()) {
                vector<int> pi; 
                M[cur_s] = pi; 
            }
            M[cur_s].push_back(i+1); 
        }
        return dp[len]; 
    }
};