/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-28 20:00:12
 	Problem       : Triangle
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
    int minimumTotal(vector<vector<int> >& triangle) {
        int size = triangle.size();
        vector<int> dp(size);
        dp[0] = triangle[0][0];
    	for(int i = 1; i < size; i++) {
    		dp[i] = dp[i-1] + triangle[i][i];
    		for(int j = i-1; j >= 0; j -- ) {
    			dp[j] = dp[j] + triangle[i][j];
    			if(j - 1 >= 0) dp[j] = min(dp[j], dp[j-1] + triangle[i][j]);
    		}
    	}
    	int ret = INF;
    	for(int i = 0; i < size; i++) ret = min(ret, dp[i]);
    	return ret;        
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE

	vector<vector<int> > V;
	for(int i = 1; i <= 4; i++) {
		vector<int> v;
		for(int j = 1; j <= i; j++) v.push_back(j);
		V.push_back(v);
	}

	Solution x = Solution();
	cout<<x.minimumTotal(V);
	
	return 0; 
}