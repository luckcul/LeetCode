class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    bool dfs(vector<vector<int>> &vis, vector<vector<char>>& board, int x, int y, string word, int index, int n, int m) {
        if(index >= word.size() - 1) return true;
        bool ret = false;
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0]; 
            int ny = y + dir[i][1];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
            if(word[index+1] != board[nx][ny] ) continue;
            vis[nx][ny] = 1;
            ret = ret || dfs(vis, board, nx, ny, word, index+1, n, m);
            vis[nx][ny] = 0;
            if(ret) return true;
        }
        return ret;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0) return false;
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        if(m == 0) return false;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] != word[0]) continue;
                vis[i][j] = 1;
                bool ans = dfs(vis, board, i, j, word, 0, n, m);
                vis[i][j] = 0;
                if(ans) return true;
            }
        }
        return false;
    }
};