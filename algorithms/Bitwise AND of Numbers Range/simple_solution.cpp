class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0; 
        int base = 1;
        while(m != n) {
            m >>= 1;
            n >>= 1;
            base <<= 1;
        }
        return base * m; 
    }
};