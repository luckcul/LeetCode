class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s = s.size(); 
        int len_t = t.size(); 
        if(len_s == 0) return true; 
        int t_index = 0, s_index = 0; 
        while(t_index < len_t) {
            if(t[t_index] == s[s_index]) {
                s_index++; 
                if(s_index >= len_s) return true;
            }
            t_index++; 
        }
        return false; 
    }
};