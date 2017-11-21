class Solution {
private:
    static bool cmp(pair<int, int> x, pair<int, int> y) {
        if(x.first == y.first) return x.second < y.second;
        return x.first < y.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int length = envelopes.size(); 
        if(length < 1) return 0; 
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(length+1, 1);
        // dp[0] = 0;
        int last_index = -1, ret = 1;
        for(int i = 1; i < length; i++) {
            // dp[i+1] = max(dp[i+1], dp[last_index+1] + 1);
            for(int j = 0; j < i; j++) if(envelopes[j].first < envelopes[i].first && envelopes[j].second < envelopes[i].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};