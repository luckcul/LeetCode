/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-30 09:35:23
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
    	int factors[] = {2, 3, 5};
    	set<int> S;
    	S.insert(1);
    	for(int i = 0 ; i < n-1; i ++) {
    		set<int>::iterator it = S.begin();
    		for(int j = 0; j < 3; j ++) {
    			if((*it) > ((1<<31) - 1) / factors[j]) continue;
    			S.insert(factors[j] * (*it));
    		}
    		S.erase(it);
    	}
    	return *(S.begin());
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