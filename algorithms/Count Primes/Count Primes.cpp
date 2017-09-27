class Solution {
public:
    int countPrimes(int n) {
        vector<int> vis(n+1, 0);
        int ret = 0; 
        for(int i = 2; i < n; i++) {
            if(vis[i] == 0) {
                ret ++;
                for(int j = i*i; j < n; j+=i){
                    vis[j] = 1;
                }
            }
        }
        return ret;
    }
};