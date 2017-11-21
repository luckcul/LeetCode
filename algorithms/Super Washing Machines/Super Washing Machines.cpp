class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int length = machines.size();
        vector<int> sums(length + 1, 0); 
        for(int i = 0; i < length; i++) {
            sums[i+1] = sums[i] + machines[i];
        }
        if(sums[length] % length ) return -1;
        int ave = sums[length] / length; 
        int ret = 0; 
        for(int i = 0; i < length; i++) {
            int lValue = i * ave - sums[i];
            int rValue = (length - i - 1) * ave - (sums[length] - sums[i+1]);
            if(lValue > 0 && rValue > 0) ret = max(ret, lValue + rValue);
            else ret = max(ret, max(abs(lValue), abs(rValue)));
        }
        return ret;
    }
};