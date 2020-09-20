class Solution {
public:
    int check(int n, vector<vector<int>>& preferences, int x, int y, vector<vector<int>>& pairs) {
        
        for(int i = 0; i < n-1; i++) {
            if(preferences[x][i] == y) {
                break; 
            }
            int u = preferences[x][i]; 
            int x_idx=0; 
            for(int j = 0; j < n-1; j++) {
                if(preferences[u][j] == x) {
                    x_idx=j; 
                    break; 
                }
            }
            int ok_cnt = 0; 
            for(int j = x_idx+1; j < n-1; j++) {
                int v = preferences[u][j]; 
                if(v != y && v != x && v != u){
                    for(int k = 0; k < n/2; k++) {
                        if(pairs[k][0] == u && pairs[k][1] == v) return 1; 
                        if(pairs[k][0] == v && pairs[k][1] == u) return 1; 
                    }
                    // return 1; 
                }
            }
            // if(x_idx<n-2) {
            //     return 1; 
            // }
        }
        return 0; 
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ret = 0; 
        for(int i = 0; i < n/2; i++) {
            int x = pairs[i][0]; 
            int y = pairs[i][1]; 
            int r = check(n, preferences, x, y, pairs); 
            int r2 = check(n, preferences, y, x, pairs); 
            // if(r || r2) ret ++; 
            ret += r; 
            ret += r2; 
        }
        return ret; 
    }
};