class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int x, int y, int idx, int n, int m) {
        if(x < 0 || x >= n) return; 
        if(y < 0 || y >= m) return; 
        if(grid[x][y] == 1) return; 
        if(vis[x][y]) return; 
        vis[x][y] = idx; 
        for(int i = 0; i < 4; i++) {
            int dx = dir[i][0]; 
            int dy = dir[i][1]; 
            dfs(grid, vis, x+dx, y+dy, idx, n, m); 
        }
    }
    bool check(vector<vector<int>>& grid, int x, int y, int n, int m) {
        for(int i = 0; i < 4; i++) {
            int dx = dir[i][0]; 
            int dy = dir[i][1]; 
            int nx = x+dx; 
            int ny = y+dy; 
            if(nx<0 || nx>=n) return false; 
            if(ny<0 || ny>=m) return false; 
            
        }
        return true; 
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int idx = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue; 
                if(vis[i][j]) continue; 
                idx++; 
                dfs(grid, vis, i, j, idx, n, m); 
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        int boom = 0; 
        set<int> S; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) continue; 
                bool b = check(grid, i, j, n, m); 
                if(!b) S.insert(vis[i][j]); 
            }
        }
        set<int>::iterator it; 
        for(it = S.begin(); it !=S.end(); it++) {
            cout<<*it<<endl;
        }
        return idx -S.size(); 
        
    }
};