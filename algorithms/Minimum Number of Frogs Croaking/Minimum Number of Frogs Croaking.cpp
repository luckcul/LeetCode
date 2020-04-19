class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        vector<int> pi(6, 0); 
        int cnt = 0; 
        int ret = 0; 
        unordered_map<char, int> m; 
        m['c'] = 1; 
        m['r'] = 2; 
        m['o'] = 3; 
        m['a'] = 4; 
        m['k'] = 5; 
        bool flag = true; 
        pi[0] = 112345; 
        for(int i = 0; i < croakOfFrogs.size(); i++) {
            int idx = m[croakOfFrogs[i]]; 
            if(pi[idx-1] < 1 ) {
                flag = false; 
                break; 
            }
            pi[idx]++; 
            pi[idx-1]--; 
            cnt = 0; 
            for(int j = 1; j < 5; j++) cnt += pi[j]; 
            ret = max(ret, cnt); 
        }
        for(int i = 1; i < 5; i++) {
            if(pi[i] > 0) flag = false; 
        }
        if(flag) return ret; 
        return -1; 
    }
};