class Solution {
public:
    string toHex(int num) {
        string ret = ""; 
        if(!num) return "0"; 
        int cnt = 0; 
        while(num) {
            int val = num&(0xf); 
            if(val < 10) ret += '0' + val; 
            else ret += 'a' + val - 10; 
            num >>= 4;
            cnt ++; 
            if(cnt >= 8) break; 
        }
        reverse(ret.begin(), ret.end()); 
        return ret; 
    }
};