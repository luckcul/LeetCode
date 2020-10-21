class Solution {
public:
    int c[32][32]; 
    string kthSmallestPath(vector<int>& destination, int k) {
        memset(c, 0, sizeof(c)); 
        c[1][1] =c[1][0] = 1; 
        for(int i = 1; i <= 31; i++) {
            for(int j = 0; j <= i; j++) {
                if(j ==0 || j == i) c[i][j] = 1; 
                else c[i][j] = c[i-1][j-1] + c[i-1][j]; 
            }
        }
        string ret = ""; 
        int H = destination[1]; 
        int V = destination[0]; 
        int tk = k; 
        int th = H; 
        int tv = V; 
        for(int i = 0; i < H+V; i++) {
            cout<<th<<", "<<tv<<endl;
            if(th==0) {
                ret += "V"; 
            }
            else if(tv==0) {
                ret += "H"; 
            }
            else {
                int now_h_cnt = c[H+V-i-1][th-1]; 
                if(tk > now_h_cnt) {
                    ret += "V"; 
                    tv--; 
                    tk -= now_h_cnt; 
                }
                else {
                    th--; 
                    ret += "H"; 
                }
            }
        }
        return ret; 
    }
};