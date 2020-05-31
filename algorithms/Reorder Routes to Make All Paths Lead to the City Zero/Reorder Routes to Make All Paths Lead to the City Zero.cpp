class Solution {
public:
    struct node {
        int idx; 
        vector<pair<int, int> > next_node; 
    };
    void dfs(int now_idx, int last_idx, int & ret, vector<node> & nodes) {
        int len = nodes[now_idx].next_node.size(); 
        for(int i = 0; i < len; i++) {
            int next_idx = nodes[now_idx].next_node[i].first; 
            int f = nodes[now_idx].next_node[i].second; 
            if(next_idx == last_idx) continue; 
            if(f) ret ++; 
            dfs(next_idx, now_idx, ret, nodes); 
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<node> nodes(n); 
        int len = connections.size(); 
        for(int i = 0; i < len; i++) {
            int a = connections[i][0]; 
            int b = connections[i][1]; 
            nodes[a].next_node.push_back(make_pair(b, 1)); 
            nodes[b].next_node.push_back(make_pair(a, 0)); 
        }
        int ret = 0; 
        dfs(0, -1, ret, nodes); 
        return ret; 
    }
};