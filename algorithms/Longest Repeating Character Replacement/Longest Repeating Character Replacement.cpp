class Solution {
public:
    int characterReplacement(string s, int k) {
        int ret = 0; 
        int len = s.size(); 
        for(char ch = 'A'; ch <= 'Z'; ch++) {
            int l = 1, r = len; 
            while(l <= r) {
                int m = (l+r)>>1; 
                bool flag = check(s, k, m, ch); 
                if(flag) {
                    ret = max(ret, m); 
                    l = m+1; 
                }
                else r = m-1;
            }
        }
        return ret;         
    }
    bool check(string &s, int k, int m, char ch) {
        int cnt_not_ch = 0; 
        for(int i = 0; i < m-1; i++) {
            if(s[i] != ch) cnt_not_ch ++; 
        }
        for(int i = m-1; i < s.size(); i++) {
            if(s[i] != ch) cnt_not_ch ++; 
            if(cnt_not_ch <= k) return true; 
            if(s[i-m+1] != ch) cnt_not_ch --; 
        }
        return false; 
    }
};