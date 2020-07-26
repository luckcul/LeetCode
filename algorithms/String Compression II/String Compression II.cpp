class Solution {
    struct node {
        char ch; 
        int cnt; 
        int start_idx; 
        int end_idx; 
    }; 
public:
    int get_len(int x) {
        if(x == 1) return 0; 
        if(x < 10) return 1; 
        if(x < 100) return 2; 
        return 0;
    }
    int getLengthOfOptimalCompression(string s, int k) {
        int len = s.size(); 
        int dp[123][123]; 
        for(int i = 0; i <= len; i++) {
            for(int j = 0; j <= k; j++) {
                if(i == 0)  dp[i][j] = 0;
                else dp[i][j] = 1e9; 
            }
        }
        int last = -1; 
        vector<node> t; 
        for(int i = 1; i < len; i++) {
            if(s[i] == s[i-1]) continue; 
            node ti; 
            ti.ch = s[i-1]; 
            ti.cnt = i-last-1;
            ti.start_idx=last+1; 
            ti.end_idx=i-1; 
            t.push_back(ti); 
            last = i-1; 
        }
        node ti; 
        ti.ch=s[len-1]; 
        ti.cnt = len-last-1;
        ti.start_idx = last+1; 
        ti.end_idx=len-1; 
        t.push_back(ti); 
        int sizet = t.size(); 
        for(int i = 0; i < sizet; i++) {
            for(int j = 0; j <= k; j++) {
                // cout<<i<<", "<<j;
                dp[i+1][j] = dp[i][j] + get_len(t[i].cnt)+1; 
                
                if(t[i].cnt == 1) {
                    int last_j =j-1; 
                    if(last_j >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][last_j]);
                }
                else {
                    int last_j = j-(t[i].cnt-1); 
                    if(last_j >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][last_j]+1); 
                    
                    last_j = j-(t[i].cnt); 
                    if(last_j >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][last_j]); 
                    
                    if(t[i].cnt> 9) {
                        last_j = j-(t[i].cnt - 9); 
                        if(last_j >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][last_j]+2); 
                    }
                }
                
                // specific
                int same_cnt = 0; 
                int last_idx = i-1; 
                while(last_idx >= 0) {
                    if(t[last_idx].ch != t[i].ch) {
                        last_idx--; 
                        continue; 
                    }
                    int ch_cnt = t[i].start_idx - t[last_idx].end_idx - 1 - same_cnt;
                    int last_j = j-ch_cnt; 
                    if(last_j >= 0) dp[i+1][j] = min(dp[i+1][j], dp[last_idx][last_j]+get_len(same_cnt + t[last_idx].cnt + t[i].cnt)+1); 
                    same_cnt += t[last_idx].cnt; 
                    last_idx --; 
                }
                // cout<<", "<<dp[i+1][j]<<endl;
            }
        }
        
        int ret = 1e9; 
        for(int j = 0; j <= k; j++) ret = min(ret, dp[sizet][j]); 
        return ret; 
        
    }
};