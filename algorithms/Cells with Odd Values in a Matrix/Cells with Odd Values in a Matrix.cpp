class Solution {
public:
    void add(vector<vector<int>> &mat, int x, int y, int n, int m) {
        for(int i = 0; i < n; i++) {
            mat[i][y] ++; 
        }
        for(int j = 0; j < m; j++) {
            mat[x][j]++; 
        }
    }
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n+1, vector<int>(m+1, 0)); 
        int len = indices.size(); 
        for(int i = 0; i < len; i++) {
            int x = indices[i][0]; 
            int y = indices[i][1]; 
            add(mat, x, y, n, m); 
        }
        int ret = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j]&1) {
                    ret ++; 
                }
            }
        }
        return ret; 
    }
};