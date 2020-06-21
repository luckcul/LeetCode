class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size(); 
        int emp_i = 0; 
        vector<int> ret(n, -1); 
        bool flag = true; 
        unordered_map<int, int> M; 
        set<int> S; 
        for(int i = 0; i <n; i++) {
            if(rains[i] == 0) {
                S.insert(i); 
                continue; 
            }
            if(M.find(rains[i]) == M.end()) {
                M[rains[i]] = i; 
            }
            else {
                set<int>::iterator it = S.upper_bound(M[rains[i]]); 
                if(it == S.end()) {
                    flag = false; 
                    break; 
                }
                else{
                    ret[*it] = rains[i]; 
                    S.erase(it); 
                }
                
                M[rains[i]] = i; 
            }
        }
        // cout<<"ok"<<endl;
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0 && ret[i] == -1) ret[i] = 1;  
        }
        // cout<<"--ok"<<endl;
        if(!flag) {
            ret.clear();
            return ret; 
        }
        return ret; 
    }
};