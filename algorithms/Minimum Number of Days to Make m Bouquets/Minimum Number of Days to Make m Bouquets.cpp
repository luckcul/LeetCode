class Solution {
    bool check(int mid, vector<int>& bloomDay, int n, int m, int k) {
        int last = 0; 
        int finish_cnt = 0; 
        for(int i = 0; i < n; i++) {
            if(bloomDay[i] > mid) {
                last = 0; 
                continue; 
            }
            last ++; 
            if(last >= k) {
                last -= k; 
                finish_cnt ++; 
            }
            if(finish_cnt >= m) {
                return true; 
            }
        }
        return false; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(); 
        if(m*k > n) return -1; 
        int l = 1e9; 
        int r = 0; 
        for(int i = 0; i < n; i++) {
            l = min(l, bloomDay[i]); 
            r = max(r, bloomDay[i]); 
        }
        int ret = 1; 
        while(l <= r) {
            int mid = (l+r)/2; 
            bool f = check(mid, bloomDay, n, m, k); 
            if(f) {
                ret = mid; 
                r = mid-1; 
            }
            else {
                l = mid+1; 
            }
        }
        return ret; 
    }
};