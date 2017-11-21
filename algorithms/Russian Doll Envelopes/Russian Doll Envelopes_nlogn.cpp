class Solution {
private:
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        if(x.first == y.first) return x.second > y.second;
        return x.first < y.first;
    }
    int binary_s(vector<int> &dp, int val) {
        int l = 0, r = dp.size() - 1, ret = dp.size(); 
        while(l <= r) {
            int m = (l + r)>>1;
            if(dp[m] >= val) {
                ret = m; r = m - 1;
            }
            else l = m + 1;
        }
        return ret;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int length = envelopes.size(); 
        if(length < 1) return 0; 
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp;
        for(int i = 0; i < length; i++) {
            int index = binary_s(dp, envelopes[i].second);
            if(index >= dp.size()) dp.push_back(envelopes[i].second);
            else dp[index] = envelopes[i].second;
        }
        
        return dp.size();
    }
};