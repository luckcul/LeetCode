class Solution {
    int dirs[7][4] = {0, 0, 0, 0, 0, -1, 0, 1, -1, 0, 1, 0, 0, -1, 1, 0, 0, 1, 1, 0, -1, 0, 0, -1, -1, 0, 0, 1};
public:
    bool check(vector<vector<int>>& grid, int now_x, int now_y, int dir) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        while(true) {
            // cout<<"now pos: "<<now_x<<", "<<now_y<<endl;
            if(now_x == n-1 && now_y == m-1) {
                return true; 
            }
            int g = grid[now_x][now_y]; 
            int next_x = now_x + dirs[g][dir*2]; 
            int next_y = now_y + dirs[g][dir*2+1];
            // cout<<"next pos: "<<next_x<<", "<<next_y<<endl;
            if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
                break; 
            }
             dir = -1; 
            for(int i = 0; i < 2; i++) {
                int next_g = grid[next_x][next_y]; 
                int two_x = next_x + dirs[next_g][i*2]; 
                int two_y = next_y + dirs[next_g][i*2+1]; 
                if(two_x == now_x && two_y == now_y) {
                    dir = i; 
                    // cout<<"next's back dir: "<<dirs[next_g][i*2]<<", "<<dirs[next_g][i*2+1]<<endl;
                    // cout<<"next's dir: "<<dirs[next_g][(1-i)*2]<<", "<<dirs[next_g][(1-i)*2+1]<<endl;
                    break; 
                }
            }
            if(dir == -1) {
                break; 
            }
            now_x = next_x; 
            now_y = next_y; 
            dir = 1-dir; 
            // cout<<next_dir<<endl;
        }
        return false; 
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        return check(grid, 0, 0, 0) || check(grid, 0, 0, 1); 
    }
};