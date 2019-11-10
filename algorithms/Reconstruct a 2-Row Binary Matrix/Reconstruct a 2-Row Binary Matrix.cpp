class Solution {
public:
    void fill(vector<vector<int>> &ret, vector<int>& colsum, int a, int b) {
        int len = colsum.size(); 
        for(int i = 0; i < len; i++) {
            int x = colsum[i]; 
            if(x == 0) continue; 
            if(x == 2) {
                ret[0][i] = ret[1][i] = 1; 
                a --;
                b--; 
            }
            if(x == 1) {
                if(a >= b) {
                    a--; 
                    ret[0][i] = 1;
                }
                
                else {
                    b--; 
                    ret[1][i] = 1;
                }
            }
        }
    }
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int len = colsum.size(); 
        int tot_s = 0; 
        for(int i = 0; i < len; i++) {
            tot_s += colsum[i]; 
        }
        vector<vector<int>> ret; 
        if(upper+lower != tot_s) {
            return ret; 
        }
        int two = 0; 
        int one = 0; 
        for(int i = 0; i < len; i++) {
            if(colsum[i] == 2) two++; 
            else if(colsum[i] == 1) one++; 
        }
        int a = upper - two; 
        int b = lower - two; 
        if(a < 0 || b < 0) {
            return ret; 
        }
         vector<vector<int>> ret1(2, vector<int>(len, 0)); 
        fill(ret1, colsum, upper, lower); 
        return ret1; 
    }
};