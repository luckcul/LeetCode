class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ret; 
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        vector<int> row_min(n, 1123456); 
        vector<int> col_max(m, 0); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                row_min[i] = min(row_min[i], matrix[i][j]); 
                col_max[j] = max(col_max[j], matrix[i][j]); 
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == row_min[i] && matrix[i][j] == col_max[j]) {
                    ret.push_back(matrix[i][j]);
                }
            }
        }
        return ret; 
    }
};