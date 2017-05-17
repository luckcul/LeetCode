/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-07 15:15:49
 	Problem       : problem
************************************************ */
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
//typedef __int64 LL;

    int dp[1123][1123];
class Solution {
    int dfs(int l, int r) {
    	if(l > r) return 0;
    	if(dp[l][r]) return dp[l][r];
    	if(l == r) return dp[l][r] = 0;
    	if(l == r-1) return dp[l][r] = l;
    	if(l == r-2) return dp[l][r] = l+1;
    	int ret = INF;
    	for(int i = l; i <= r; i++) {
    		ret = min(ret, i + max(dfs(l, i-1) , dfs(i+1, r)));
    	}
    	return dp[l][r] = ret;
    }
public:
    int getMoneyAmount(int n) {
    	// memset(dp, -1, sizeof(dp));
    	return dfs(1, n);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.getMoneyAmount(10);

	return 0;
}
