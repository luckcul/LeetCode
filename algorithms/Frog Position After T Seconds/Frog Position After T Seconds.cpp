class Solution {
    
public:
    void dfs(vector<vector<int>>& edges, int n, int ti, int T, int now_idx, int last_idx, vector<double> &pro){
        if(ti >= T) {
            return ; 
        }
        int next_size = 0; 
        for(int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0]; 
            int node2 = edges[i][1]; 
            if((node1 == now_idx && node2 != last_idx) || (node2 == now_idx && node1 != last_idx)){
                next_size++; 
            }
        }
        // cout<<"now idx: "<<now_idx<<"  -- "<<"next size: "<<next_size<<endl;
        if(!next_size) return ; 
        
        double now_pro = 1.0/next_size; 
        for(int i = 0; i < edges.size(); i++) {
            int node1 = edges[i][0]; 
            int node2 = edges[i][1];
            int next_node = -1; 
            if(node1 == now_idx && node2 != last_idx) {
                next_node = node2; 
            }
            if(node2 == now_idx && node1 != last_idx) {
                next_node = node1; 
            }
            if(next_node == -1) continue; 
            pro[next_node] = pro[now_idx]*now_pro; 
            // cout<<"next_node "<<next_node<<":"<<pro[next_node]<<endl;
            dfs(edges, n, ti+1, T, next_node, now_idx, pro); 
        }
        pro[now_idx] = 0; 
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<double> pro(n+1, 0); 
        pro[1] = 1.0; 
        dfs(edges, n, 0, t, 1, -1, pro); 
        return pro[target]; 
    }
};