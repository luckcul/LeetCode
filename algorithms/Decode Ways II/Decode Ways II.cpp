/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-29 22:00:27
 	Problem       : Decode Ways II
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
typedef long long LL; 

class Solution {
	LL check(char a, char b) {
		LL ret = 0;
		if(a == '0' || a >= '3') return 0;
		if(a == '1') {
			if(b == '*') return 9;
			else return 1;
		}
		if (a == '2') {
			if(b == '*') return 6;
			else return b <= '6'? 1:0;
		}
		if(b == '*') return 15;
		return b <= '6' ? 2:1;
	}
public:
    int numDecodings(string s) {
        int length = s.size();
        LL mod = 1000000007;
        if(length == 0) return 0;
        vector<LL> dp(length+1, 0); 
        dp[0] = 1;
        for(int i = 0; i < length; i++) {
        	if(s[i] != '0') {
        		if(s[i] == '*') dp[i+1] = dp[i] * (LL)9;
        		else dp[i+1] = dp[i];
        		dp[i+1] %= mod;
        	}
        	if(i >= 1){
        		dp[i+1] += dp[i-1] * check(s[i-1], s[i]);
        		dp[i+1] %= mod;
        	}
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