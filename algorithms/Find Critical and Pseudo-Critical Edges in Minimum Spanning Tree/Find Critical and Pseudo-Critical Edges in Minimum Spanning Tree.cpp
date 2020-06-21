class Solution {
    int par[112]; 
    int node_num; 
    int add_edge_num; 
    int map[1123]; 
    
    int find_par(int x) {
        if(x == par[x]) return x; 
        return par[x] = find_par(par[x]); 
    }
    int merge(int a, int b) {
        int fa = find_par(a); 
        int fb = find_par(b); 
        if(fa == fb) {
            return 0; 
        }
        add_edge_num ++; 
        par[fb] = fa; 
        return 1; 
    }
    int mst(int must_idx, int ignore_idx, vector<vector<int>>& edges) {
        int ret = 0; 
        add_edge_num = 0; 
        for(int i = 0; i < node_num; i++) {
            par[i] = i; 
        }
        if(must_idx >= 0) {
            int idx = map[must_idx]; 
            int f = merge(edges[idx][0], edges[idx][1]); 
            if(f) ret += edges[idx][2]; 
        }
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0]; 
            int b = edges[i][1]; 
            int wi = edges[i][2]; 
            if(edges[i][3] == ignore_idx) continue; 
            int f = merge(a, b); 
            if(f) ret += wi; 
        }
        return ret; 
    }
    static bool cmp(vector<int> &x, vector<int> &y) {
        return x[2] < y[2]; 
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> ret1, ret2; 
        node_num = n; 
        int edge_num = edges.size(); 
        for(int i = 0; i < edge_num; i++) {
            edges[i].push_back(i); 
        }
        sort(edges.begin(), edges.end(), cmp); 
        for(int i = 0; i < edge_num; i++) {
            map[edges[i][3]] = i; 
        }
        int w = mst(-1, -1, edges); 
        if(add_edge_num != n-1) {
            return vector<vector<int>>(2, vector<int>()); 
        }
        for(int i = 0; i < edge_num; i++) {
            int idx = edges[i][3]; 
            int wi = mst(-1, idx, edges); 
            if(add_edge_num != n-1 || wi != w) {
                ret1.push_back(idx); 
                continue; 
            }
            
            wi = mst(idx, -1, edges); 
            if(add_edge_num==n-1 && wi == w) {
                ret2.push_back(idx); 
            }
        }
        vector<vector<int>> ret; 
        ret.push_back(ret1); 
        ret.push_back(ret2); 
        return ret; 
    }
};