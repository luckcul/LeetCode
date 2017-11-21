class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        // vector<vector<int>> dp(50000, vector<int>(3, -1));
        map<int, pair<int, int>> M; 
        map<int, int> C;
        for(int i = 0; i < nums.size(); i++) {
            if(M.find(nums[i]) == M.end()) {
                // dp[nums[i]][0] = 1; dp[nums[i]][1] = i;
                M[nums[i]] = make_pair(i, i);
                C[nums[i]] = 1;
            }
            else {
                // dp[nums[i]][0] ++; dp[nums[i]][2] = i;
                M[nums[i]].second = i;
                C[nums[i]] ++;
            }
        }
        int maxFre = 1, minLen = 1;
        for(int i = 0; i < nums.size(); i++) {
            int nowLen = M[nums[i]].second - M[nums[i]].first + 1;
            int nowFre = C[nums[i]];
            if(nowFre > maxFre) {
                maxFre = nowFre;
                minLen = nowLen;
            }
            else if(nowFre == maxFre) {
                minLen = min(minLen, nowLen);
            }
        }
        return minLen; 
    }
};