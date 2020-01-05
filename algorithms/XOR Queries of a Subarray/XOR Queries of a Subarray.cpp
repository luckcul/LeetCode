class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int len = arr.size(); 
        vector<int> cache(len+1, 0); 
        for(int i = 0; i < len; i++) {
            cache[i+1] = cache[i] ^ arr[i]; 
        }
        vector<int> ret; 
        for(int i = 0; i < queries.size(); i++) {
            int s = queries[i][0]; 
            int e = queries[i][1]; 
            ret.push_back(cache[e+1] ^ cache[s] );
        }
        return ret; 
    }
};