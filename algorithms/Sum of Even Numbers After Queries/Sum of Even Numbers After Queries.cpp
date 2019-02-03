class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ret; 
        int len_A = A.size(); 
        int len_q = queries.size(); 
        int sum = 0; 
        for(int i = 0; i < len_A; i++) {
            int tmp = A[i] > 0 ? A[i]:-A[i]; 
            if(!(tmp&1)) sum += A[i]; 
        }
        for(int i = 0; i < len_q; i++) {
            int idx = queries[i][1]; 
            int val = queries[i][0]; 
            
            int tmp = A[idx] > 0? A[idx]:-A[idx]; 
            if(!(tmp&1)) sum -= A[idx]; 
            A[idx] += val; 
            tmp = A[idx] > 0? A[idx]:-A[idx]; 
            if(!(tmp&1)) sum += A[idx]; 
            ret.push_back(sum); 
        }
        return ret; 
    }
};