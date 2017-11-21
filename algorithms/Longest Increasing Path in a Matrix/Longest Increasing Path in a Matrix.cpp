class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        if(!len1) return 0; 
        int len2 = matrix[0].size(); 
        if(!len2) return 0; 
        vector<vector<int>> vis(len1, vector<int>(len2, 0));
        int ret = 0; 
        for(int i = 0; i < len1; i++) {
            for(int j = 0; j < len2; j++) {
                dfs(i, j, matrix, vis);
                ret = max(ret, vis[i][j]);
            }
        }
        return ret;
    }
    int dfs(int x, int y, vector<vector<int>> &matrix, vector<vector<int>> &vis){
        if(vis[x][y]) return vis[x][y];
        int ret = 0; 
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || nx >= matrix.size() || ny < 0 || ny >= matrix[0].size()) continue;
            if(matrix[nx][ny] <= matrix[x][y]) continue;
            ret = max(ret, dfs(nx, ny, matrix, vis));
        }
        vis[x][y] = ret + 1;
        return ret+1;
    }
};