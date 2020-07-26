class Solution {
public:
    int minFlips(string target) {
        int len = target.size(); 
        int idx = len-1; 
        int last = -1; 
        int s = 0; 
        for(int i = len-1; i>=0; i--) {
            if(target[i]-'0' == last) {
                continue; 
            }
            else {
                s++; 
                last = target[i]-'0';
            }
        }
        if(target[0] == '0') s--; 
        return s;
    }
};