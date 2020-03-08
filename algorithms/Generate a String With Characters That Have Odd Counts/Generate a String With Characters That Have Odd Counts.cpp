class Solution {
public:
    string generateTheString(int n) {
        string ret = ""; 
        int tn = n; 
        int num = 499; 
        char ch = 'a'; 
        while(tn>0) {
            if(num > tn) {
                num -= 2; 
                continue; 
            }
            for(int i = 0; i < num; i++) {
                ret += ch; 
            }
            ch ++; 
            tn -= num; 
        }
        return ret; 
    }
};