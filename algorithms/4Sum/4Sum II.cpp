class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> M; 
        int length = A.size(); 
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) {
                M[A[i] + B[j]] ++;
            }
        }
        int ret = 0; 
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < length; j++) {
                ret += M[-C[i] -D[j]]; 
            }
        }
        return ret; 
    }
};