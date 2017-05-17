/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-04-19 09:27:35
 	Problem       : problem
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
#define INF 1000000000
//typedef __int64 LL;

class Solution {
public:
    int bulbSwitch(int n) {
    	return sqrt(1.0*n);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
	Solution x = Solution();
	cout<<x.bulbSwitch(123456);

	return 0;
}
