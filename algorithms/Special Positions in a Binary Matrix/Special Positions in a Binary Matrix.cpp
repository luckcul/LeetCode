class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        vector<int> a(n+1, 0); 
        vector<int> b(m+1, 0); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                a[i] += mat[i][j]; 
                b[j] += mat[i][j]; 
            }
        }
        int ret = 0; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && a[i] == 1 && b[j] == 1) ret ++; 
            }
        }
        return ret; 
    }
};