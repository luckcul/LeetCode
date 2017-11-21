class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(); 
        if(!n) return ;
        int m = matrix[0].size(); 
        if(!m) return ;
        bitset<1000> bits1;
        bitset<1000> bits2;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j]) continue;
                bits1[i] = 1;
                bits2[j] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0) continue;
                if(bits1[i] || bits2[j]) matrix[i][j] = 0;
            }
        }
    }
};