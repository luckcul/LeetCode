/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-10-20 15:36:22
 	Problem       : super pow
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
	int myPow(int a, int b, int mod) {
		// b < 10
		int ret = 1; 
		for(int i = 1; i <= b; i++) 
			ret *= a, ret %= mod;
		return ret;
	}
    int superPow(int a, vector<int>& b) {
        int mod = 1337;
    	a %= mod;
        int len = b.size();
        int ret = 1;
        for(int i = len-1; i >= 0; i--) {
        	ret *= myPow(a, b[i], mod);
        	ret %= mod;
        	a = myPow(a, 10, mod);
        	a %= mod;
        }
        return ret;
    }
};
int main() {
	Solution x =  Solution();
	vector<int> v; 
	v.push_back(2); v.push_back(0); 
	v.push_back(0);
	printf("%d\n", x.superPow(2147483647,v));
	
	return 0; 
}