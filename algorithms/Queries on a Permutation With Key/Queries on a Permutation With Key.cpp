class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums(m+1, 0); 
        vector<int> vis(m+1, 0); 
        for(int i = 1; i <= m; i++) {
            nums[i-1]=i; 
            vis[i] = i-1; 
        }
        vector<int> ret; 
        for(int i = 0; i < queries.size(); i++) {
            int op = queries[i]; 
            ret.push_back(vis[op]);// cout<<i<<", "<<op<<endl;
            for(int j = vis[op]; j >= 1; j--) {// cout<<" j"<<j<<endl;
                nums[j] = nums[j-1]; 
                vis[nums[j-1]] = j;
                // cout<<"endj"<<endl;
            }
            // cout<<"last1"<<endl;
            nums[0] = op; 
            vis[op] = 0; 
            // cout<<"last2"<<endl;
        }
        // cout<<"ok"<<endl;
        return ret; 
        
    }
};