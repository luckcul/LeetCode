class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size(); 
        sort(piles.begin(), piles.end()); 
        int m = n/3*2; 
        int id = 0; 
        int ret = 0; 
        for(int i = n-1; i >n-1-m; i--) {
            if(id&1) ret += piles[i]; 
            id = 1-id; 
        }
        return ret; 
    }
};