class Solution {
public:
    int find(int x, vector<int> &par) {
        if(x != par[x]) par[x] = find(par[x], par); 
        return par[x]; 
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int, int> > e[3]; 
        for(int i = 0; i < edges.size(); i++) {
            int type = edges[i][0]; 
            pair<int, int> p = make_pair(edges[i][1], edges[i][2]); 
            e[type-1].push_back(p); 
        }
        // cout<<"ok"<<endl;
        vector<int> par(n+1, 0); 
        for(int i = 0; i<= n; i++) par[i] = i; 
        int ret = 0; 
        int cou = 0; 
        for(int i = 0; i < e[2].size(); i++) {
            int x = e[2][i].first; 
            int y = e[2][i].second; 
            int px = find(x, par); 
            int py = find(y, par); 
            if(px!=py) {
                par[py] = px; 
                cou++; 
            }
            else {
                ret++; 
            }
        }
        // cout<<"cou: "<<cou<<endl;
        // cout<<ret<<endl;
        
        int cou1 = cou; 
        vector<int> par1(par.begin(), par.end()); 
        for(int i = 0; i < e[0].size(); i++) {
            int x = e[0][i].first; 
            int y = e[0][i].second; 
            int px = find(x, par1); 
            int py = find(y, par1); 
            if(px != py) {
                par1[py] = px; cou1++; 
            }
            else ret++; 
        }
        
        int cou2 = cou; 
        vector<int> par2(par.begin(), par.end()); 
        for(int i = 0; i < e[1].size(); i++) {
            int x = e[1][i].first; 
            int y = e[1][i].second; 
            int px = find(x, par2); 
            int py = find(y, par2); 
            if(px != py) {
                par2[py] = px; cou2++; 
            }
            else ret++; 
        }
        if(cou1 < n-1 || cou2 < n-1) {
            return -1; 
        }
        return ret; 
    }
};