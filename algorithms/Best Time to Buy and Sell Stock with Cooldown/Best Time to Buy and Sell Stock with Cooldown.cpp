#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size(); 
        if(length <= 1) return 0; 
        for(int i = length - 1; i >= 1; i--) {
            prices[i] = prices[i] - prices[i-1];
        }
        vector<vector<int>> dp(length+1, vector<int>(3, -1000000000));
        dp[0][1] = dp[0][0] = dp[0][2] = 0; 
        for(int i = 1; i < length; i++) {
                dp[i][0] = max(dp[i-1][0] + prices[i], dp[i-1][2] + prices[i]);
                dp[i][1] = dp[i-1][0];
                dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[length-1][0], max(dp[length-1][1], dp[length-1][2]));
    }
};

int main() {
    Solution x = Solution();
    int in[] = {2,111,2,66,3,4,2,9,11};
    vector<int> inv(in, in + 9);
    cout<<x.maxProfit(inv);
}