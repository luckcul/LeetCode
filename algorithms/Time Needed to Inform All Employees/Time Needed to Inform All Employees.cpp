class Solution {
    struct node {
        int idx; 
        vector<int> next; 
        int val; 
    }; 
    
public:
    void dfs(vector<node> &p, int now_idx, int & ret, int now_ret) {
        if(now_idx < 0) return; 
        
        ret = max(ret, now_ret); 
        int next_size = p[now_idx].next.size(); 
        if(next_size <= 0) return; 
        for(int i = 0; i < next_size; i++) {
            int next_idx = p[now_idx].next[i]; 
            dfs(p, next_idx, ret, now_ret+p[now_idx].val); 
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // node p[N]; 
        vector<node> p(n+1); 
        for(int i = 0; i < n; i++) {
            int now_idx = i; 
            int manager_idx = manager[i]; 
            if(manager_idx == -1) continue; 
            p[manager_idx].next.push_back(now_idx); 
        }
        for(int i = 0; i < n; i++) {
            p[i].val = informTime[i]; 
        }
        int ret = 0; 
        dfs(p, headID, ret, 0); 
        return ret; 
    }
};