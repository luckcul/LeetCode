class Solution {
public:
    int clumsy(int N) {
        // vector<int> nums1; 
        int ret = 0; 
        bool first = true; 
        for(int i = N; i >= 1;) {
            int muls = i; 
            i--; 
            if(i >= 1) {
                muls *= i; 
                i--; 
            }
            if(i >= 1) {
                muls /= i; 
                i--; 
            }
            if(first) {
                first = false; 
            }
            else {
                muls = -muls;
            }
            if(i >= 1) {
                muls += i;
                i--;
            }
            ret += muls;
        }
        return ret; 
    }
};