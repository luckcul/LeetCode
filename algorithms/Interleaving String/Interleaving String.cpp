/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-28 09:49:58
 	Problem       :  Interleaving String O((n+m)*(n+m))
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
		if(length3 != length1 + length2) return false;
		vector<set<pair<int, int>>> xy(length3 + 1);
		// set<pair<int, int>> temp; temp.insert(make_pair(-1, -1));
		xy[0].insert(make_pair(-1, -1));
		for(int i = 0; i  < length3; i++) {
			for(set<pair<int, int>>::iterator it = xy[i].begin(); it  != xy[i].end(); it ++) {
				int xi = it->first, yi = it->second;
				if(xi + 1 < length1 && s3[i] == s1[xi + 1]) {
					xy[i+1].insert(make_pair(xi+1, yi));
				}
				if(yi + 1 < length2 && s3[i] == s2[yi + 1]) {
					xy[i+1].insert(make_pair(xi, yi + 1));
				}
			}
		}
		if(xy[length3].size() <= 0) return false;
		return true;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}