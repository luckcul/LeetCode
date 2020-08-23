class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(); 
        set<int> s; 
        s.insert(0); 
        s.insert(n+1); 
        if(n == m) {
            return n; 
        }
        for(int i = n-1; i >= 0; i--) {
            set<int>::iterator it; 
            int val = arr[i]; 
            it = s.lower_bound(val); 
            int mv = *it; 
            it--; 
            int minv = *it; 
            // cout<<mv<<", "<<minv<<endl;
            if(mv-val-1==m || val-minv-1==m) {
                return i; 
            }
            s.insert(val); 
        }
        return -1; 
    }
};