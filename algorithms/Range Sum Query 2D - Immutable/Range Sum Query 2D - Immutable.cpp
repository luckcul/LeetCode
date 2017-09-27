class NumMatrix {
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>> matrix) {
        v = matrix;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < v[i].size(); j++) {
                int top = (i > 0 ? v[i-1][j] : 0);
                int left = (j > 0 ? v[i][j-1] : 0);
                int topleft = (i > 0 && j > 0 ? v[i-1][j-1] : 0);
                v[i][j] = v[i][j] + left + top - topleft;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int top = row1 - 1;
        int left = col1 - 1;
        int topArea = (top >= 0 ? v[top][col2]:0);
        int leftArea = (left >= 0 ? v[row2][left]:0);
        int topleftArea = (top>=0 && left >= 0 ? v[top][left] : 0);
        return v[row2][col2] - leftArea - topArea + topleftArea;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */