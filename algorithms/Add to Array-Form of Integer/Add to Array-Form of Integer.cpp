class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret; 
        int len = A.size(); 
        int k = K, idx = len-1; 
        int last = 0;
        while(k || idx >= 0) {
            int a = 0; 
            if(k) {
                a = k%10; 
                k /= 10; 
            }
            int b = 0; 
            if(idx >= 0) {
                b = A[idx]; 
                idx--; 
            }
            last += a+b; 
            ret.push_back(last%10); 
            last /= 10; 
        }
        if(last) ret.push_back(last); 
        reverse(ret.begin(), ret.end()); 
        return ret; 
    }
};