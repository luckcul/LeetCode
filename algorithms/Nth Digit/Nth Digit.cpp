class Solution {
    int getDigital(int num, int th, int length) {
        for(int i = 0; i < length - th; i++) num /= 10;
        return num % 10;
    }
public:
    int findNthDigit(int n) {
        int headcount[10],base=9;
        headcount[0] = 0;
        for(int i = 1; i < 9; i++) {
            headcount[i] = headcount[i-1] + i * base;
            base *= 10;
        }
        headcount[9] = (1<<31)-1;
        int length = 0;
        for(int i = 0; i < 10; i++) {
            if(n <= headcount[i]) {
                length = i; break;
            }
        }
        int last = headcount[length-1];
        int newNth_ = n - last;
        int newNth = newNth_ / length;
        int th = newNth_ % length;
        int inNum = 0;
        for(int i = 1; i < length; i++) inNum *= 10, inNum += 9;
        inNum += newNth;
        int ret = (th == 0 ? inNum%10 : getDigital(inNum + 1, th, length));
        return ret;

    }
};