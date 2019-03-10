class Solution {
    int sol(vector<int>& A, vector<int>& B, int x) {
        int ret = 0; 
        int inf = 1123456;
        int length = A.size(); 
        for(int i = 0; i < length; i++) {
            if(A[i] == x) continue; 
            if(B[i] == x) {
                ret++; continue; 
            }
            return inf; 
        }
        return ret; 
    }
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int inf = 1123456;
        int ret = inf; 
        for(int i = 1; i <= 6; i++) {
            ret = min(ret, sol(A, B, i)); 
            ret = min(ret, sol(B, A, i)); 
        }
        return ret >= inf? -1:ret; 
    }
};