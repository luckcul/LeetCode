class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ret = 0; 
        int n = mat.size(); 
        int m = mat[0].size(); 
        vector<vector<int>> s(n+1, vector(m+1, 0)); 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + mat[i][j]; 
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) continue; 
                for(int ni = i; ni < n; ni++) {
                    if(mat[ni][j] == 0) continue; 
                    for(int nj = j; nj < m ;nj++) {
                        int su = (ni-i+1)*(nj-j+1); 
                        if(s[ni+1][nj+1] + s[i][j] - s[ni+1][j] - s[i][nj+1] == su) {
                            ret ++; 
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        return ret; 
    }
};