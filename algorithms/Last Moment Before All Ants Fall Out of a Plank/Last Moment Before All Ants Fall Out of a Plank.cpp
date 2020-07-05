class Solution {
    int status[2][11234][2]; 
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0; 
        for(int i = 0; i < left.size(); i++) {
            ret = max(ret, left[i]); 
            // ret = max(ret, n-left[i]); 
        }
        for(int i = 0; i < right.size(); i++) {
            // ret = max(ret, right[i]);
            ret = max(ret, n-right[i]); 
        }
        return ret; 
        // vector<int> status[2]; 
//         int now_idx = 0; 
//         memset(status, 0, sizeof(status)); 
//         for(int i = 0; i < left.size(); i++) {
//             status[0][left[i]][0] = 1; 
//         }
//         for(int i = 0; i < right.size(); i++) {
//             status[0][right[i]][1] = 1; 
//         }
//         bool flag = false; 
//         while(true) {
//             for(int i = 0; i <= n; i++) {
//                 status[1-now_idx][i][0] = 0; 
//                 status[1-now_idx][i][1] = 0; 
//             }
//             for(int i = 0; i <= n; i++) {
                
//             }
//         }
    }
};