// TLE
class Solution {
    set<pair<int,int>> vis;
    bool flag; 
public:
    bool canMeasureWater(int x, int y, int z) {
        this->flag = false; 
        dfs(0, 0, x, y, z);
        return flag; 
    }
    void dfs(int now_x, int now_y, int x, int y, int z) {
        if(flag) return ;
        if(vis.find(make_pair(now_x, now_y)) != vis.end()) return ; 
        vis.insert(make_pair(now_x, now_y)); 
        if(now_x == z || now_y == z || now_x + now_y == z) {
            flag = true; return ;
        }
        // out
        dfs(0, now_y, x, y, z); 
        dfs(now_x, 0, x, y, z); 
        // in 
        dfs(x, now_y, x, y,z ); 
        dfs(now_x, y, x, y, z); 
        // transf
        int need_x = x - now_x; 
        int need_y = y - now_y; 
        dfs(max(0, x-need_y), min(y, now_y+now_x), x, y, z); 
        dfs(min(x, now_x+now_y), max(0, y-need_x), x, y, z); 
    }
};