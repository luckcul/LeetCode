class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int length = 8; 
        int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0}; 
        int Ri=-1, Rj=-1; 
        for(int i = 0; i < length; i++) {
            if(Ri != -1) break;
            for(int j = 0; j < length; j++) {
                if(board[i][j] == 'R') {
                    Ri = i; Rj = j; 
                    break;
                }
            }
        }
        int cnt = 0; 
        for(int i = 0; i < 4; i++) {
            int nx = Ri+dir[i][0]; 
            int ny = Rj+dir[i][1]; 
            while(nx >= 0 && nx < length && ny >= 0 && ny < length) {
                if(board[nx][ny] == 'B') break;
                if(board[nx][ny] == 'p') {
                    cnt++; break;
                }
                nx += dir[i][0]; 
                ny += dir[i][1];
            }
        }
        return cnt;
    }
};