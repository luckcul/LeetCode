class Solution {
    struct TreeNode {
        int val;
        vector<int> nextnode;
        TreeNode(int x) : val(x){}
    };
public:
    int dfs(int now_idx, int last_idx, vector<TreeNode>& nodes, int &ret) {
        if(now_idx >= nodes.size()) {
            return 0; 
        }
        // cout<<now_idx<<endl;
        int has_app = nodes[now_idx].val; 
        for(int i = 0; i < nodes[now_idx].nextnode.size(); i++) {
            int next = nodes[now_idx].nextnode[i]; 
            if(next == last_idx) continue; 
            int f = dfs(next, now_idx, nodes, ret); 
            if(f) {
                has_app |= f; 
                ret += 2; 
            }
        }
        return has_app; 
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<TreeNode> nodes; 
        for(int i = 0; i < n; i++) {
            nodes.push_back(TreeNode(hasApple[i])); 
        }
        for(int i = 0; i < edges.size(); i++) {
            int a = edges[i][0]; 
            int b = edges[i][1]; 
            nodes[a].nextnode.push_back(b); 
            nodes[b].nextnode.push_back(a); 
        }
        int ret = 0; 
        dfs(0, -1, nodes, ret); 
        return ret; 
    }
};