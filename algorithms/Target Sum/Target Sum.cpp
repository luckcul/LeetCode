/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-27 20:02:11
 	Problem       : Target Sum
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

class Solution {
private:
	int dp[2][2020];
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	if(abs(S) > 1000) return 0;
    	int upper = 2000;
        memset(dp, 0, sizeof(dp));
        dp[0][1000] = 1;
        int now = 0;
        for(int i = 0; i < int(nums.size()); i++) {
        	int last = now;
        	now = now^1;
        	memset(dp[now], 0, sizeof(dp[now]));
        	for(int j = 0; j <= upper; j++) {
        		int nextValue = j + nums[i];
        		if(nextValue <= upper) dp[now][nextValue] += dp[last][j];

        		nextValue = j - nums[i];
        		if(nextValue >= 0 ) dp[now][nextValue] += dp[last][j];
        	}
        }
        return dp[now][1000+S];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int arr[] = {1,2, 1, 1};
	vector<int> V(arr, arr+4);
	Solution x = Solution();
	cout<<x.findTargetSumWays(V, 1);
	
	return 0; 
}