/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-15 19:19:44
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
// typedef __int64 LL;

class Solution {
	int vis1[30], vis2[11234][30];

public:
    bool checkInclusion(string s1, string s2) {
    	memset(vis1, 0, sizeof(vis1));
    	for(int i = 0; i < s1.size(); i++) {
    		vis1[s1[i] - 'a'] ++;
    	}
    	memset(vis2, 0, sizeof(vis2));
    	for(int i = 0; i < s2.size(); i++) {
    		for(int j = 0; j <= 'z' - 'a'; j++) vis2[i+1][j] = vis2[i][j];
    		vis2[i+1][s2[i] - 'a'] ++;
    	}
    	int len1 = s1.size(), len2 = s2.size();
    	for(int i = 0; i <= len2 - len1; i++) {
    		bool flag = true;
    		for(int j = 0; j <= 'z' - 'a'; j++) {
    			if(vis2[i+len1][j] - vis2[i][j] == vis1[j]) continue;
    			flag = false;
    			break;
    		}
    		if(flag) return true;
    	}
    	return false;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.checkInclusion("abc", "bcsdf");
	return 0;
}
