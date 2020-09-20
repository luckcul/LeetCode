class Solution {
public:
    bool isTransformable(string s, string t) {
        int n = s.size(); 
        vector<int> vis(11, 0); 
        vector<int> s_gre(n+1, 0); 
        vector<vector<int>> s_ten(11); 
        
        for(int i = 0; i < n; i++) {
            vis[s[i]-'0'] ++; 
            for(int j = 9; j>s[i]-'0'; j--) {
                s_gre[i] += vis[j]; 
            }
            s_ten[s[i]-'0'].push_back(s_gre[i]); 
        }
        vector<int> s_ten_idx(11, 0); 
        
        vector<int> t_vis(11, 0); 
        for(int i = 0; i < n; i++) {
            int dig = t[i] - '0'; 
            int idx = s_ten_idx[dig]; 
            int max_idx = s_ten[dig].size(); 
            if(idx >= max_idx) {
                return false; 
            }
            t_vis[dig]++; 
            int t_sum = 0; 
            for(int j = 9; j>dig; j--) {
                t_sum += t_vis[j]; 
            }
            if(t_sum > s_ten[dig][idx]) {
                return false; 
            }
            s_ten_idx[dig]++; 
        }
        return true; 
    }
};