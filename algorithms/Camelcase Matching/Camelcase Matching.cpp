class Solution {
public:
    bool subcheck(string q, string p) {
        // cout<<q<<endl;
        // cout<<p<<endl;
        int idx = 0; 
        if(p[0] >= 'A' && p[0] <= 'Z') {
            if(q[0] != p[0]) return false; 
            idx++; 
        }
        
        vector<int> visq(30, 0); 
        vector<int> visp(30, 0); 
        for(int i = idx; i < q.size(); i++) visq[q[i] - 'a']++; 
        for(int i = idx; i < p.size(); i++) visp[p[i] - 'a']++; 
        for(int i = 0; i <= 26; i++) {
            if(visp[i] > visq[i]) return false; 
        }
        return true; 
    }
    bool check(string query, string pattern) {
        int len_q = query.size(); 
        int len_p = pattern.size(); 
        int i = -1, j = -1; 
        while(i < len_q && j < len_p ) {
            int ti = i; 
            int tj = j; 
            ti++; 
            tj++; 
            while(ti < len_q && query[ti] >= 'a') {
                ti++; 
            } 
            while(tj < len_p && pattern[tj] >= 'a') {
                tj++; 
            }
            i = i<0? 0:i;
            j = j<0? 0:j;
            bool flag = subcheck(query.substr(i, ti-i), pattern.substr(j, tj-j)); 
            if(!flag) return false; 
            i = ti; 
            j = tj; 
        }
        if(i < len_q || j < len_p) return false; 
        return true; 
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int len = queries.size(); 
        vector<bool> ret; 
        for(int i = 0; i < len; i++) {
            ret.push_back(check(queries[i], pattern)); 
        }
        return ret; 
    }
};