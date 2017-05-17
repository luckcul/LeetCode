/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-15 20:08:48
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
	int vis1[60], vis2[60];
	int hash(char ch) {
		if(ch <= 'Z') return ch - 'A';
		return ch - 'a' + 26;
	}
public:
    string minWindow(string s, string t) {
    	memset(vis1, 0, sizeof(vis1));
    	memset(vis2, 0, sizeof(vis2));
    	for(int i = 0; i < int(t.size()); i++) {
    		vis1[hash(t[i])] ++;
    	}
    	int totalOK = 0;
    	for(int i = 0; i < 26*2; i++) {
    		if(vis2[i] >= vis1[i]) totalOK ++;
    	}
    	int i = 0, j = -1, l, r, Min = INF;
    	int len = s.size();
    	while(i < len){
    		bool flag = true;
    		while(j < len-1) {
    			j++;
    			vis2[hash(s[j])] ++;
    			if(vis2[hash(s[j])] == vis1[hash(s[j])]) totalOK ++;
    			if(totalOK >= 26*2){
    				flag = false;  break;
    			}
    		}
    		if(flag) break;
    		while(i < len) {
    			int next = vis2[hash(s[i])];
    			if(next == vis1[hash(s[i])]) break;
    			vis2[hash(s[i])] --;
    			i ++;
    		}
    		if(j - i < Min) {
    			Min = j - i;
    			l = i; r = j;
    		}
    		if(vis2[hash(s[i])] == vis1[hash(s[i])]) totalOK --;
    		vis2[hash(s[i])] --;
    		i++;
    	}
    	if(Min >= INF) return "";
    	return s.substr(l, r-l+1);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.minWindow("abc", "b");
	return 0;
}
