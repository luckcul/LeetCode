/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-08-21 10:32:20
 	Problem       : Remove Boxes
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
public:
    int removeBoxes(vector<int>& boxes) {
        int dp[103][103][103];
        memset(dp, -1, sizeof(dp));
        return dfs(dp, boxes, 0, boxes.size()-1, 0);
    }
    int dfs(int dp[103][103][103], vector<int>& boxes, int l, int r, int m) {
    	if(l > r) return 0;
    	if(dp[l][r][m] > 0) return dp[l][r][m];
    	int ret = (m + 1) * (m + 1) + dfs(dp, boxes, l+1, r, 0);
    	for(int i = l + 1; i <= r; i ++) {
    		if(boxes[i] == boxes[l]) {
    			ret = max(ret, dfs(dp, boxes, l+1, i-1, 0) + dfs(dp, boxes, i, r, m+1));
    		}
    	}
    	return dp[l][r][m] = ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}