class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int len = arr.size(); 
        bool ret=false; 
        for(int i = 0; i < len; i++) {
            bool ok=true; 
            // cout<<endl<<i<<endl;
            for(int j = 1; j <= k-1; j++) {
                int start = i+j*m; 
                int end = i+(j+1)*m-1; 
                // cout<<start<<", "<<end<<endl;
                if(end >= len) {
                    ok=false; 
                    break; 
                }
                for(int ki = 0; ki < m; ki++) {
                    if(arr[ki+i] != arr[ki+start]) {
                        ok=false; 
                        break; 
                    }
                }
            }
            if(ok) {
                return true; 
            }
        }
        return false; 
    }
};