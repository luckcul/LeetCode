/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-02-15 14:39:59
 	Problem       : dp
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
	int dp[110][110];
	int v[666], w[666];
public:
    int findMaxForm(vector<string>& strs, int m, int n) {// #600 , 100, 100
        memset(dp, -1, sizeof(dp));
        memset(v, 0, sizeof(v));
        memset(w, 0, sizeof(w));
        dp[0][0] = 0;
        for(int i = 0; i < strs.size(); i++) {
        	for(int j = 0; j < strs[i].size(); j++) {
        		if(strs[i][j] == '0') v[i] ++; 
        		else w[i] ++;
        	}
        }
        for(int i = 0; i < strs.size(); i++) {
        	for(int j = m; j >= 0; j--) {
        		for(int k = n; k >= 0; k-- ) {
        			int nj = j - v[i];
        			int nk = k - w[i];
        			if(nj < 0 || nk < 0 || dp[nj][nk] < 0) continue;
        			dp[j][k] = max(dp[j][k], dp[nj][nk] + 1);
        		}
        	}
        }
        int ans = 0;
        for(int i = 0; i <= m; i++) {
        	for(int j = 0; j <= n; j++) {
        		ans = max(ans, dp[i][j]);
        	}
        }
        return ans;
    }
};

int main() {
	vector<string> strs;
	strs.push_back("10");
	strs.push_back("0001");
	strs.push_back("11101");
	strs.push_back("1");
	strs.push_back("0");
	Solution x = Solution();
	cout<<x.findMaxForm(strs, 3, 100);
	
	return 0; 
}