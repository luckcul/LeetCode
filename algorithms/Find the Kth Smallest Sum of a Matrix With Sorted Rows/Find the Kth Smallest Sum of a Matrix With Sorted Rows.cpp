class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(); 
        int m = mat[0].size(); 
        vector<int> v[2]; 
        int now_idx = 0; 
        v[0].push_back(0); 
        for(int i = 0; i < n; i++) {
            // cout<<"i : "<<i<<endl;
            int next_idx = 1-now_idx; 
            int upper = min(200, int(v[now_idx].size()) ); 
            // cout<<"\t vi m :"<<upper<<", "<<m<<endl;
            for(int vi = 0; vi < upper; vi++) {
                for(int j = 0; j < m; j++) {
                    v[next_idx].push_back(v[now_idx][vi] + mat[i][j]); 
                }
            }
            sort(v[next_idx].begin(), v[next_idx].end()); 
            v[now_idx].clear(); 
            now_idx = next_idx; 
        }
        return v[now_idx][k-1]; 
    }
};