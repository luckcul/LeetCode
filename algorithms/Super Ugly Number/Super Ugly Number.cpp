/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-30 10:44:53
 	Problem       : Super Ugly Number
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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /*n (0, 1e6) k (0, 100) primes < 1000*/
    	vector<int> V(n);
    	V[0] = 1;
    	int k = primes.size();
    	vector<int> p(k, 0);
    	for(int i = 1; i < n; i++) {
    		int min_ = (1<<31) - 1;
    		for(int j = 0; j < k; j++) {
    			min_ = min(min_, primes[j] * V[p[j]]);
    		}
    		for(int j = 0; j < k; j++) {
    			if(min_ == primes[j] * V[p[j]]) p[j] ++;
    		}
    		V[i] = min_;
    	}
    	return V[n-1];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}