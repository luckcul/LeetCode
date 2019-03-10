class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int length = A.size(); 
        sort(A.begin(), A.end()); 
        int idx = 0; 
        while(idx < length) {
            if(A[idx] >= 0 || K <= 0) {
                break;
            }
            A[idx] = -A[idx]; 
            K--; 
            idx++; 
        }
        sort(A.begin(), A.end()); 
        if(K > 0 && K%2 == 1) {
            A[0] = -A[0]; 
        }
        int ret = 0; 
        for(int i = 0; i < length; i++) {
            ret += A[i]; 
        }
        return ret; 
    }
};