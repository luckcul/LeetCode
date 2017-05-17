/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-03 17:08:21
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

class Solution {
	int vis[23][23];

    int sol(vector<int>& nums, int l, int r) {
    	if(l == r) return nums[l];
    	else {
    		int ans1 = vis[l+1][r] == -INF ? (vis[l+1][r] = sol(nums, l+1, r)) : vis[l+1][r];
    		int ans2 = vis[l][r-1] == -INF ? (vis[l][r-1] = sol(nums, l, r-1)) : vis[l][r-1];
    		return max(nums[l] - ans1, nums[r] - ans2);
    	}
    	// return l == r? nums[l] : max(nums[l] - sol(nums, l+1, r), nums[r] - sol(nums, l, r-1));
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int len = nums.size();
    	for(int i = 0; i < 21; i++) for(int j = 0; j < 21; j++) vis[i][j] = -INF;
    	return sol(nums, 0, len-1) >= 0;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	std::vector<int> v;
	v.push_back(1);
	v.push_back(1);
	// v.push_back(6);
	Solution x = Solution();
	cout<<x.PredictTheWinner(v);

	return 0;
}
