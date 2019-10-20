class Solution {
    struct node {
        int q, w, e, r; 
    }; 
    
    bool check(vector<node> &num, int len, int x) {
        if(x == 0) {
            if(num[len].q == len/4 && num[len].w == len/4 && num[len].e == len/4 && num[len].r == len/4) 
                return true; 
            return false; 
        }
        int target = len/4; 
        for(int i = x; i <= len; i++) {
            int qi = num[i].q - num[i-x].q; 
            int wi = num[i].w - num[i-x].w; 
            int ei = num[i].e - num[i-x].e; 
            int ri = num[i].r - num[i-x].r; 
            int needq = target - (num[len].q - qi); 
            int needw = target - (num[len].w - wi); 
            int neede = target - (num[len].e - ei); 
            int needr = target - (num[len].r - ri); 
            if(needq >=0 && needw>=0 && neede>=0 && needr>=0) {
                return true; 
            }
        }
        return false; 
    }
public:
    int balancedString(string s) {
        int len = s.size(); 
        vector<node> num(len+1); 
        num[0].q = 0; 
        num[0].w = 0; 
        num[0].e = 0; 
        num[0].r = 0; 
        for(int i = 0; i < len; i++) {
            num[i+1].q = num[i].q; 
            num[i+1].w = num[i].w; 
            num[i+1].e = num[i].e; 
            num[i+1].r = num[i].r; 
            if(s[i] == 'Q') num[i+1].q++; 
            else if(s[i] == 'W') num[i+1].w++; 
            else if(s[i] == 'E') num[i+1].e++; 
            else num[i+1].r++; 
        }
        int l = 0; 
        int r = len;
        int ret = 0; 
        while(l <= r) {
            int m = (l+r)>>1; 
            if(check(num, len, m)) {
                r = m-1; 
                ret = m; 
            }
            else l = m+1; 
        }
        return ret; 
    }
};