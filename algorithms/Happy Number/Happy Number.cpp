/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-25 14:26:05
 	Problem       : Happy Number
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
	bool vis[1123];
	int test(int n) {
		if(n < 1000) {
			if(vis[n]) return -1;
			vis[n] = true;
		}
		int temp = 0;
		while(n) {
			int x = n % 10;
			temp += x*x;
			n /= 10;
		}
		return temp;
	}
public:
    bool isHappy(int n) {
        memset(vis, 0, sizeof(vis));
        while(true){
        	int nextN = test(n);
        	if(nextN == -1) return false;
        	if(nextN == 1) return true;
        	n = nextN;
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.isHappy(123465789);
	
	return 0; 
}