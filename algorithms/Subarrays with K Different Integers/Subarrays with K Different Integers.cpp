class Solution {
    void add(unordered_map<int, int> &m, int &cnt, int val) {
        if(m[val] == 0) cnt++; 
        m[val] ++; 
    }
    void remove(unordered_map<int, int> &m, int &cnt, int val) {
        if(m[val] == 1) cnt--; 
        m[val] --; 
    }
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        unordered_map<int, int> m1, m2; 
        int cnt1 = 0; 
        int cnt2 = 0; 
        int r1, r2; 
        r1 = r2 = -1; 
        int len = A.size(); 
        int ret = 0; 
        for(int i = 0; i < len; i++) {
            while(r1 < len && cnt1 < K) {
                r1++; 
                if(r1 >= len) break;
                add(m1, cnt1, A[r1]); 
            }
            while(r2 < len && cnt2 <= K) {
                r2++;
                if(r2 >= len) break;
                add(m2, cnt2, A[r2]); 
            }
            ret += r2-r1;
            remove(m1, cnt1, A[i]); 
            remove(m2, cnt2, A[i]);
        }
        return ret;
    }
};