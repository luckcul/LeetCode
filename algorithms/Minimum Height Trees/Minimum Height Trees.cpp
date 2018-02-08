class Solution {
    struct edge {
        int u, v, next;
    };
    void add(int u, int v, vector<edge> &edges, int &index, vector<int> &hh) {
        edges[index].u = u; edges[index].v = v; 
        edges[index].next = hh[u]; 
        hh[u] = index++;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ret; 
        if(n < 1) return ret;
        if(n < 2) {
            ret.push_back(0); return ret;
        }
        if(n < 3) {
            ret.push_back(0); ret.push_back(1); return ret; 
        }
        int edge_size = edges.size(); 
        vector<edge> edgess(edge_size*2+1);
        vector<int> hh(n+1, -1); 
        vector<int> cnt(n+1, 0);
        int tot = 0; 
        for(int i = 0; i < edges.size(); i++) {
            add(edges[i].first, edges[i].second, edgess, tot, hh); 
            add(edges[i].second, edges[i].first, edgess, tot, hh);
            cnt[edges[i].first] ++; 
            cnt[edges[i].second] ++;
        }
        queue<int> Q; 
        for(int i = 0; i < n; i++) if(cnt[i] <= 1) Q.push(i); 

        while(n > 2) {
            int size = Q.size(); 
            n -= size; 
            for(int i = 0; i < size; i++) {
                int now = Q.front(); Q.pop(); 
                for(int j = hh[now]; j != -1; j = edgess[j].next) {
                    cnt[edgess[j].v] --; 
                    if(cnt[edgess[j].v] == 1) Q.push(edgess[j].v);
                }
            }
        }
        while(!Q.empty()) {
            ret.push_back(Q.front()); Q.pop(); 
        }
        return ret; 
        

    }
};