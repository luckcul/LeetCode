class Solution {
public:
    int integerReplacement(int n) {
        int num = n; 
        int ret = 0, last = 0; 
        while(num) {
            int bit = num & 1;
            if(bit) {
                last ++;
            }
            else {
                
                if(last >= 1) ret ++;
                if(last > 1) last = 1;
                else last = 0;
            }
            ret ++;
            num >>= 1;
        }
        if(last == 1) ret -= 1;
        else if(last == 2) ;
        else ret += 1;
        return ret;
    }
};