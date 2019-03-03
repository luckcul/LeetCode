class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<set<int>> tru(N, set<int>()); 
        vector<set<int>> trued(N, set<int>()); 
        int length = trust.size(); 
        for(int i = 0; i < length; i++) {
            int a = trust[i][0]; 
            int b = trust[i][1]; 
            a--; b--; 
            tru[a].insert(b); 
            trued[b].insert(a); 
        }
        for(int i = 0; i < N; i++) {
            bool flag = true; 
            if(tru[i].size() != 0) flag = false; 
            if(trued[i].size() != N-1) flag = false; 
            if(flag) return i+1; 
        }
        return -1; 
    }
};