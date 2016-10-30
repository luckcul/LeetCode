/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-10-27 18:40:06
 	Problem       : number of digit one
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
	int lim[20], len;
	int dp[20][15];
public:
	void toString(int n) {
		len = 0;
		while(n){
			len ++;
			lim[len] = n%10;
			n /= 10;
		}
	}
	int dfs(int l, int num, bool flag) {
		if(!flag && dp[l][num] != -1) return dp[l][num];
		if(l == 0) return num == 0;
		int bound = flag ? lim[l] : 9;
		int ret = 0;
		for(int i = 0; i <= bound; i++) {
			if(i == 1 && num > 0)  ret += dfs(l-1, num-1, flag && (i == bound));
			else if(i == 1 && num <= 0) continue;
			else ret += dfs(l-1, num, flag && (i == bound));
		}
		return flag ? ret : dp[l][num] = ret;
	}
	int sol(int num) {		
        memset(dp, -1, sizeof(dp));
        return dfs(len, num, true);
	}
    int countDigitOne(int n) {
        int ret = 0; 
        toString(n);
        for(int i = 1; i <= len; i++) {
        	ret += i * sol(i);
        }
        return ret;
    }
};

int main() {

	Solution x = Solution();
	printf("%d\n", x.countDigitOne((1<<31)-(1<<29) ));
	
	return 0; 
}