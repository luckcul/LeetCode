class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs(int x, int y, int borderX, int borderY, vector<vector<bool>> &mat, int n, int m, vector<vector<int>> &matrix) {
        if(mat[x][y]) return ;
        mat[x][y] = true;
        for(int i = 0; i < 4; i++) {
            int dx = dir[i][0], dy = dir[i][1];
            int nx = x + dx, ny = y + dy;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(nx == borderX || ny == borderY || matrix[nx][ny] >= matrix[x][y]) {
                dfs(nx, ny, borderX, borderY, mat, n, m, matrix);
            }
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ret;
        int n = matrix.size();
        if(n == 0) return ret;
        int m = matrix[0].size();
        vector<vector<bool>> mat1(n, vector<bool>(m, false));
        vector<vector<bool>> mat2(n, vector<bool>(m, false));
        dfs(0, 0, 0, 0, mat1, n, m, matrix);
        dfs(n-1, m-1, n-1, m-1, mat2, n, m, matrix);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat1[i][j] && mat2[i][j]) ret.push_back(make_pair(i,j));
            }
        }
        return ret;
    }
};