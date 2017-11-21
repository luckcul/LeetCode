class Solution {
    static bool cmp(vector<int> x, vector<int> y) {
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0] < y[0];
    }
    int bs(int startIndex, int val, vector<vector<int>>& pairs) {
        int ret = -1; 
        int l = startIndex, r = pairs.size() - 1; 
        while(l <= r) {
            int m = (l + r) >> 1;
            if(pairs[m][0] > val) {
                ret = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ret;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(pairs.size(), 0);
        int lastM = 0; 
        for(int i = 0; i < pairs.size(); i++) {
            int head = pairs[i][1];
            dp[i] = max(lastM, dp[i]);
            lastM = max(lastM, dp[i]);
            int tail = bs(i+1, head, pairs);
            if(tail < 0) continue;
            dp[tail] = max(dp[tail], dp[i] + 1);
        }
        return lastM + 1;
    }
};