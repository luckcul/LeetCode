class Solution {
    int vis[33][33];
    int n, m; 
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
public:
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if(i>= n || j >= m) return ; 
        if(i<0 || j < 0) return ; 
        if(grid[i][j] == 0) return ; 
        if(vis[i][j] == 1) return ; 
        vis[i][j] = 1; 
        // cout<<i<<", "<<j<<endl;
        for(int ii = 0; ii < 4; ii++) {
            int nx = i+dir[ii][0]; 
            int ny = j+dir[ii][1]; 
            // cout<<"nxy"<<nx<<", "<<ny<<endl;
            dfs(grid, nx, ny); 
        }
    }
    int find_cluster_cnt(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis)); 
        int cnt = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 and vis[i][j] == 0) {
                    cnt++; 
                    dfs(grid, i, j); 
                    // cout<<"-------------"<<endl;
                }
            }
        }
        // cout<<cnt<<endl;
        return cnt; 
    }
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size(); 
        memset(vis, 0, sizeof(vis)); 
        int cnt = find_cluster_cnt(grid); 
        if(cnt != 1) {
            return 0; 
        }
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) continue; 
                grid[i][j] = 0; 
                int cnt_ = find_cluster_cnt(grid); 
                if(cnt_!= 1) {
                    return 1; 
                }
                grid[i][j] = 1; 
            }
        }
        return 2; 
    }
};