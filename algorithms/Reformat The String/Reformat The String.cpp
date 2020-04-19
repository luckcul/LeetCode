class Solution {
public:
    string reformat(string s) {
        string a; 
        string b; 
        int la = 0; 
        int lb = 0; 
        int len = s.size(); 
        for(int i = 0; i < len; i++) {
            if(s[i] >= '0' && s[i] <='9') {
                la ++; 
                a += s[i]; 
            }
            else {
                lb ++; 
                b += s[i]; 
            }
        }
        if(la < lb) {
            swap(a, b); 
            swap(la, lb); 
        }
        if(la-lb>1) {
            return ""; 
        }
        string ret = ""; 
        int idx_a = 0; 
        int idx_b = 0; 
        while(true) {
            bool flag = false; 
            if(idx_a < la) {
                ret += a[idx_a]; 
                idx_a ++; 
                flag = true; 
            }
            if(idx_b < lb) {
                ret += b[idx_b]; 
                idx_b ++; 
                flag = true; 
            }
            if(!flag) break;
        }
        return ret; 
    }
};