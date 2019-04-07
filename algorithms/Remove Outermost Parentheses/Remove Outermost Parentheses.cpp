class Solution {
public:
    string removeOuterParentheses(string S) {
        string ret = ""; 
        int idx = 0; 
        int len = S.size(); 
        for(int i = 0; i < len; i++) {
            if(S[i] == '(') {
                idx++; 
            }
            else idx--; 
            if(!idx) continue; 
            if(idx == 1 && S[i] == '(') {
                continue;           
            }
            ret += S[i];    
        }
        return ret; 
    }
};