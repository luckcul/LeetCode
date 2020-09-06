class Solution {
public:
    string modifyString(string s) {
        int len = s.size(); 
        for(int i = 0;i < len; i++) {
            if(s[i] != '?') continue; 
            for(char c = 'a'; c <= 'z'; c++ ) {
                if( ( i <= 0 || c!=s[i-1]) && (i>=len-1 || c!=s[i+1])) {
                    s[i] = c; 
                    break;
                }
            }
        }
        return s; 
    }
};