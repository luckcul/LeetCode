/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-07 14:26:21
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
#include <map>
#include <set>
using namespace std;
#define INF 1000000000
typedef long long LL;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        LL l = 1, r = n;
        LL mid;
        while(l <= r) {
        	mid = (l+r)>>1;
        	// cout<<mid<<endl;
        	int t = guess(mid);
        	if(t == 0) return int(mid);
        	else if(t > 0) {
        		l = mid + 1;
        	}
        	else {
        		r = mid - 1;
        	}
        }
        return 0;
    }
};
