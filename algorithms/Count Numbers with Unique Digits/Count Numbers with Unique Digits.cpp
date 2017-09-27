class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int temp = 9, ret = 10; 
        for(int i = 1; i < min(n, 10); i++) {
            temp *= (9-i+1);
            ret += temp;
        }
        return ret;
    }
};