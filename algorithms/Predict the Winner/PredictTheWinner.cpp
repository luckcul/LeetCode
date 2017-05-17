/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-03 14:41:24
 	Problem       : predict the winner
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
    int sum[2];

	void dfs(vector<int>& nums, int l, int r, int index) {
		if(l == r) {
			sum[index] = nums[l];
			return ;
		}
		int tempSum[2][2];

		sum[0] = sum[1] = 0;
		dfs(nums, l+1, r, index^1);
		tempSum[0][0] = sum[0], tempSum[0][1] = sum[1];

		sum[0] = sum[1] = 0;
		dfs(nums, l, r-1, index^1);
		tempSum[1][0] = sum[0], tempSum[1][1] = sum[1];
		if(tempSum[0][index] + nums[l] > tempSum[1][index] + nums[r]){
			sum[index] = tempSum[0][index] + nums[l];
			sum[index^1] = tempSum[0][index^1];
		}
		else{
			sum[index] = tempSum[1][index] + nums[r];
			sum[index^1] = tempSum[1][index^1];
		}
	}
public:
    bool PredictTheWinner(vector<int>& nums) {
    	int len = nums.size();
    	dfs(nums, 0, len-1, 0);
    	return sum[0] >= sum[1] ? true:false;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	std::vector<int> v;
	v.push_back(1);
	v.push_back(5);
	v.push_back(2);
	Solution x = Solution();
	cout<<x.PredictTheWinner(v);

	return 0;
}
