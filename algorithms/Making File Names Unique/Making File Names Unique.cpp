class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        int n = names.size(); 
        unordered_map<string, int> M; 
        vector<string> ret; 
        for(int i = 0; i < n; i++) {
            string name = names[i]; 
            if(M.find(name) == M.end()) {
                ret.push_back(name); 
                M[name] = 1;
            }
            else {
                int start = M[name]; 
                while(true) {
                    string x = name; 
                    x += "("; 
                    x += to_string(start); 
                    x += ")"; 
                    if(M.find(x) == M.end()) {
                        ret.push_back(x); 
                        M[x] = 1;
                        break;
                    }
                    else {
                        start ++; 
                    }
                }
                M[name] = start +1; 
            }
        }
        return ret; 
    }
};