class Solution {
public:
    int maxUniqueSplit(string s) {
        int len = s.size(); 
        // set<string> S; 
        unordered_map<string, int> M; 
        int ret = 0; 
        for(int i = 0; i < (1<<(len-1)); i++) {
            string tmp_s = ""; 
            // S.clear();
            M.clear(); 
            bool ok = true; 
            int cnt = 0; 
            for(int j = 0; j < len; j++) {
                tmp_s += s[j]; 
                if((i>>j)&1) cnt++; 
                if((i>>j)&1 || j==len-1) {
                // cout<<tmp_s<<", "; 
                    // if(S.find(tmp_s) == S.end()) {
                    if(M.find(tmp_s) == M.end()) {
                        // S.insert(tmp_s); 
                        M[tmp_s] = 1; 
                    }
                    else {
                        ok = false; 
                        break;
                    }
                    tmp_s=""; 
                }
            }
            // cout<<endl;
            if(ok) {
                ret = max(ret, cnt); 
            }
            
        }
        return ret+1; 
    }
};