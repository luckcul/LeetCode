class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> M; 
        int len = paths.size(); 
        for(int i = 0; i< len; i++) {
            string a = paths[i][0]; 
            string b = paths[i][1]; 
            if(M.find(a) == M.end()) {
                M[a] = 0; 
            }
            if(M.find(b) == M.end()) {
                M[b] = 0; 
            }
            M[a] --; 
            M[b] ++;  
        }
        string ret= ""; 
        for(unordered_map<string, int>::iterator it = M.begin(); it!=M.end(); it++) {
            cout<<it->first<<", "<<it->second<<endl;
            if(it->second == 1) {
                ret = it->first; 
            }
        }
        return ret; 
    }
};