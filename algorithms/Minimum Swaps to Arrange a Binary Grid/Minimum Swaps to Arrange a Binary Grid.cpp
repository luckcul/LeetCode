class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(); 
        vector<int> s; 
        for(int i = 0; i < n; i++) {
            int si = 0; 
            for(int j = n-1; j>=0; j--) {
                if(grid[i][j] == 0) si++; 
                else {
                    break;
                }
            }
            s.push_back(si); 
        }
        int ret = 0; 
        for(int i = 0; i < n-1; i++) {
            int need = n-i-1; 
            int idx = -1; 
            for(int j = i; j < n; j++) {
                if(s[j]>= need) {
                    idx = j; 
                    break;
                }
            }
            if(idx == -1) {
                return -1; 
            }
            for(int j = idx; j > i; j--) {
                swap(s[j], s[j-1]); 
                ret ++; 
            }
        }
        return ret; 
    }
};