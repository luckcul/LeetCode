class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.size(); 
        string ret = ""; 
        int i = len-1; 
        int last = -1; 
        int has = 0; 
        while(i>=0) {
            if(has >= 3) {
                last = -1; has = 0; 
            }
            if(s[i] == '#') {
                last = 0; 
                has = 1; 
            }
            else {
                if(has) {
                    if(has==1) {
                        last = s[i] - '0';
                    }
                    else {
                        last = (s[i] - '0')*10+last; 
                        char ch = 'a'+last-1;
                        ret = ret +  ch; 
                    }
                    has++; 
                }
                else {
                    char ch = 'a'+s[i] - '1';
                    ret =  ret + ch; 
                }
            }
            // cout<<ret<<endl;
            i--;
        }
        string ans = ""; 
        for(int i = ret.size()-1; i>=0; i--) {
            ans += ret[i]; 
        }
        return ans; 
    }
};