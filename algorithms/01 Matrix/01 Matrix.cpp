class Solution {
    void sol(vector<vector<int>> &matrix, vector<vector<int>> &ret, int x1, int y1, int add1, int x2, int y2, int add2) {
        for(int i = x1; i != y1; i += add1) {
            for(int j = x2; j != y2; j += add2) {
                if(matrix[i][j] == 0) ret[i][j] = 0;
                else {
                    // if(i == x1 || j == x2) continue;
                    if(i != x1) ret[i][j] = min(ret[i][j], 1 + ret[i - add1][j]); 
                    if(j != x2) ret[i][j] = min(ret[i][j], 1 + ret[i][j - add2]);
                }
            }
        }
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        vector<vector<int>> ret(n, vector<int>(m, 1e9));
        sol(matrix, ret, 0, n, 1, 0, m, 1); 
        sol(matrix, ret, 0, n, 1, m-1, -1, -1);
        sol(matrix, ret, n-1, -1, -1, 0, m, 1);
        sol(matrix, ret, n-1, -1, -1, m-1, -1, -1);
        return ret;
    }
};