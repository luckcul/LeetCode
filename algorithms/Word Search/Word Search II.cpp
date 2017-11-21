class Solution {
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<vector<pair<int, int>>> index(26, vector<pair<int, int>>());
        vector<string> ret;
        int n = board.size(); 
        if(!n) return ret;
        int m = board[0].size(); 
        if(!m) return ret;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                index[board[i][j] - 'a'].push_back(make_pair(i, j));
            }
        }
        unordered_set<string> S;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i = 0; i < words.size(); i++) {
            if(S.find(words[i]) != S.end()) continue;
            S.insert(words[i]);
            for(int j = 0; j < index[words[i][0] - 'a'].size(); j++) {
                pair<int, int> p = index[words[i][0] - 'a'][j];
                int x = p.first, y = p.second;
                // if(i == 2) cout<<x<<" "<<y<<endl;
                vis[x][y] = true;
                bool flag = dfs(x, y, words[i], 0, board, vis);
                vis[x][y] = false;
                if(flag) {
                    ret.push_back(words[i]);
                    break;
                }
            }
        }
        return ret;
    }
    bool dfs(int x, int y, string &s, int index, vector<vector<char>> &board, vector<vector<bool>> &vis) {
        if(index == s.size() - 1) {
            return true;
        }
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < 4; i++) {
            int nx = x + dir[i][0]; 
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] != s[index+1]) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = true;
            bool flag = dfs(nx, ny, s, index+1, board, vis);
            vis[nx][ny] = false;
            if(flag) return true;
        }
        return false;
    }
};