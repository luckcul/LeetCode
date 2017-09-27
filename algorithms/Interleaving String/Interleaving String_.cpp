/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-28 10:32:25
 	Problem       : Interleaving String
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
    bool isInterleave(string s1, string s2, string s3) {
		int length1 = s1.size();
		int length2 = s2.size();
		int length3 = s3.size();
		if(length1 + length2 != length3) return false;
		vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1));
		for(int i = 0; i < length1 + 1; i++) {
			for(int j = 0; j < length2 + 1; j++) {
				if(i == 0 && j == 0) dp[i][j] = true;
				else if(i == 0) dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);
				else if(j == 0) dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);
				else dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
			}
		}
		return dp[length1][length2];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}