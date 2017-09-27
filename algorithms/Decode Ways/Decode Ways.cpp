/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-29 21:42:51
 	Problem       : Decode Ways
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
    int numDecodings(string s) {
        int length = s.size();
        if(length == 0) return 0;
        vector<int> dp(length+1, 0);
        dp[0] = 1;
        for(int i = 0; i < length; i++) {
        	if(s[i] != '0') dp[i+1] = dp[i];
        	if(i >= 1 && s[i-1] != '0' && (s[i-1] - '0') * 10 + (s[i] - '0') <= 26) dp[i+1] += dp[i-1];
        }
        return dp[length];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}