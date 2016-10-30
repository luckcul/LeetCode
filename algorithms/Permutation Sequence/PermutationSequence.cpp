/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-10-27 14:01:42
 	Problem       : problem
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

class Solution {
	int mark[11];
public:
	int find(int k) {
		int cou = 0;
		for(int i = 1; i <= 9; i++){
			if(!mark[i]) cou++;
			if(cou >= k) return i;
		}
	}
    string getPermutation(int n, int k) {
    	stringstream ss;
        memset(mark, 0, sizeof(mark));
        k = k-1;
        int fac[10];
        fac[0] = 1;
        for(int i = 1; i <= 9; i++) fac[i] = fac[i-1] * i;
    	for(int i = n-1; i >= 0; i--) {
    		int tmp = k / fac[i];
    		k -= tmp * fac[i];
    		int ai = find(tmp + 1);
    		ss<<ai;
    		mark[ai] = 1;
    	}
    	return ss.str();
    }
};
