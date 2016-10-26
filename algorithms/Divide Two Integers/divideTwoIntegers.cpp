/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-10-25 22:35:19
 	Problem       : divide two integer
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
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool flag = false;
        LL a, b;
        a = dividend, b = divisor;
        if(a < 0) {
        	flag = !flag;
        	a = -a;
        }
        if(b < 0) {
        	flag = !flag;
        	b = -b;
        }
        
        LL l, r, m, ret;
        l = 0, r = a, ret = 0;
        while(l <= r) {
        	m = (l+r)>>1;
        	if(m*b <= a) {
        		ret = m; l = m+1;
        	}
        	else r = m-1;
        }
        if(flag) ret = -ret;
        if(ret > (1<<31)-1) ret = (1<<31)-1;
        return ret;
    }
};
int main() {
	Solution x = Solution();
	printf("%d\n", x.divide(-2147483648, -1));	
	return 0; 
}