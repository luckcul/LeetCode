/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-04 09:14:28
 	Problem       : game tree (alpha-belta pruning) time limit out
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
	map<int, bool> M;
	int minMax( int status, int goal, int now, int len) {
		if(M.find(status) != M.end()) return M[status];
		for(int i = 0; i < len; i++) {
			int val = i+1;
			if(status & (1<<i)) {
				int newStatus = status ^ (1<<i);
				if(now + val >= goal) return M[status] = true;
				bool temp = minMax( newStatus, goal, now+val, len);
				if(temp == false) return M[status] = true;
			}
		}
		return M[status] = false;
	}
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
    	return minMax( (1<<maxChoosableInteger) - 1, desiredTotal, 0, maxChoosableInteger);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.canIWin(20, 40);

	return 0;
}
