/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-26 08:22:15
 	Problem       : Reverse Bits
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
    uint32_t reverseBits(uint32_t n) {
    	uint32_t ret = 0;
        for(int i = 0; i < 32; i++) {
        	ret <<= 1;
        	ret |= (n & 1);
        	n >>= 1;
        }
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}