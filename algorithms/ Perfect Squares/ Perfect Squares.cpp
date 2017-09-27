/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-08-24 22:08:35
 	Problem       : Perfect Squares
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
    int numSquares(int n) {
        vector<int> dp(n+1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
        	for(int j = 1; j * j <= i; j++) {
        		dp[i] = min(dp[i], dp[i - j*j] + 1);
        	}
        }
        return dp[n];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}