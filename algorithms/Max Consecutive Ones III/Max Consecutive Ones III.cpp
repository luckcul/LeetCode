class Solution {
    bool judge(vector<int> &A, int K, int x) {
        int len = A.size(); 
        if(x > len) return false; 
        int num[2]; 
        num[0] = num[1] = 0; 
        for(int i = 0; i < x; i++) {
            num[A[i]] ++; 
        }
        if(K >= num[0]) return true; 
        for(int i = x; i < len; i++) {
            int idx_last = i-x;
            num[A[idx_last]]--; 
            num[A[i]]++; 
            if(K >= num[0]) return true; 
        }
        return false; 
    }
public:
    int longestOnes(vector<int>& A, int K) {
        int len = A.size(); 
        int l = 0, r = len; 
        int ret = 0; 
        while(l <= r) {
            int m = (l+r)/2; 
            bool flag = judge(A, K, m); 
            if(flag) {
                l = m+1; 
                ret = m; 
            }
            else {
                r = m-1; 
            }
        }
        return ret; 
    }
};