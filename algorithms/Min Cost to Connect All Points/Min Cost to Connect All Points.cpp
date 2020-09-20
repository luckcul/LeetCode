class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(); 
        vector<vector<int>> dis(n+1, vector<int>(n+1, 0)); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dis[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); 
            }
        }
        vector<int> vis(n+1, 0); 
        vis[0] = 1; 
        vector<int> min_dis(n+1, 0); 
        long long ret = 0; 
        for(int i = 0; i < n; i++) min_dis[i] = dis[0][i]; 
        for(int i = 0; i < n-1; i++) {
            int min_v = 1123456789; 
            int min_idx = -1; 
            for(int j = 0; j < n; j++) {
                if(vis[j]) continue; 
                if(min_dis[j] < min_v) {
                    min_v = min_dis[j]; 
                    min_idx = j; 
                }
            }
            ret += min_v; 
            vis[min_idx] = 1; 
            for(int j = 0; j < n; j++) {
                if(min_dis[j] > dis[min_idx][j]) 
                    min_dis[j] = dis[min_idx][j]; 
            }
        }
        return ret; 
    }
};