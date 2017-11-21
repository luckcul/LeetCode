class Solution {
public:
    int getSum(int a, int b) {
        while(b) {
            int nowA = a ^ b;
            int nowB = a & b;
            a = nowA; b = nowB<<1;
        }
        return a; 
    }
};