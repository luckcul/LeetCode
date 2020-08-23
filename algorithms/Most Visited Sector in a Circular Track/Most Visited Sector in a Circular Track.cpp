class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> s(n+1, 0); 
        int len = rounds.size(); 
        int idx = 1; 
        while(idx < len) {
            int st = rounds[idx-1]; 
            int ed = rounds[idx]; 
            while(st != ed) {
                s[st]++; 
                cout<<st<<" ";
                st ++; 
                if(st>n) st=1;
            }
            // s[st]++;
            // cout<<st<<endl;
            cout<<endl;
            idx++; 
        }
        s[rounds[len-1]]++; 
        int max_v = 0; 
        vector<int> ret; 
        for(int i = 1; i <= n; i++) {
            cout<<s[i]<<" ";
            if(s[i] > max_v) {
                max_v= s[i]; 
                ret.clear(); 
                ret.push_back(i); 
            }
            else if(s[i] == max_v) {
                ret.push_back(i); 
            }
        }
        return ret; 
    }
};