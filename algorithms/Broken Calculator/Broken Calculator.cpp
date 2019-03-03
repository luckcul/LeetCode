class Solution {
public:
    int brokenCalc(int X, int Y) {
        // *2, -1
        int cnt = 0;
        while(Y > X) {
            Y = Y&1 ? Y+1:Y>>1;
            cnt++; 
        }
        return cnt + X-Y;
    }
};