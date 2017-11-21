class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() <= 2) return 0; 
        int ret = 0; 
        int last = A[1] - A[0], count = 2;
        for(int i = 2; i < A.size(); i++) {
            int diff = (A[i] - A[i-1]);
            if(diff == last) count ++; 
            else {
                if(count >= 3) ret += (count - 2) * (count - 1) / 2;
                last = diff;
                count = 2; 
            }
        }
        if(count >= 3) ret += (count - 2) * (count - 1) / 2;
        return ret;
    }
};