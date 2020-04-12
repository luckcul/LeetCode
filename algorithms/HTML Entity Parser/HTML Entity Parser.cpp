class Solution {
public:
    string entityParser(string text) {
        string ret = ""; 
        string s[6] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"}; 
        string e[6] = {"\"", "'", "&", ">", "<", "/"}; 
        int n = text.size(); 
        for(int i = 0; i < n; i++) {
            // cout<<i<<endl;
            bool match = false; 
            for(int j = 0; j < 6; j++) {
                bool f = false; 
                int js = s[j].size(); 
                for(int k = 0; k < js; k++) {
                    if(k+i >= n) break; 
                    if(text[i+k] != s[j][k]) break; 
                    if(k == js-1) f=true; 
                }
                if(f) {
                    i += js-1; 
                    ret += e[j]; 
                    match=true; 
                    break; 
                }
            }
            if(!match) ret += text[i]; 
            // cout<<ret<<endl;
        }
        return ret; 
    }
};