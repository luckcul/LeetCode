/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-25 21:52:39
 	Problem       : Perfect Number
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
    bool checkPerfectNumber(int num) {
    	if(num <= 1) return false;
        int s = 1;
        for(int i = 2; i*i <= num; i++) {
        	if(num % i) continue;
        	s += i;
        	if(i*i != num) s += num/i;
        }
        return num == s;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}