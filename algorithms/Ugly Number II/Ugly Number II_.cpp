/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-30 10:27:33
 	Problem       : Ugly Number II
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
    int nthUglyNumber(int n) {
    	vector<int> V(n);
    	V[0] = 1;
    	int p1, p2, p3;
    	p1 = p2 = p3 = 0;
    	for(int i = 1; i < n; i++) {
    		int minValue = min(min(V[p1] * 2, V[p2] * 3), V[p3] * 5);
    		if(minValue == V[p1] * 2) p1 ++;
    		if(minValue == V[p2] * 3) p2 ++;
    		if(minValue == V[p3] * 5) p3 ++;
    		V[i] = minValue;
    		// cout<<V[i]<<endl;
    	}
    	return V[n-1];
    }
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.nthUglyNumber(1407);
	
	return 0; 
}