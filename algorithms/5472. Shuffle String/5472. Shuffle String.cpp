class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ret(s); 
        int len = indices.size(); 
        for(int i = 0; i < len; i++) {
            int idx=indices[i]; 
            // ret += s[idx]; 
            ret[idx] = s[i]; 
        }
        return ret; 
    }
};