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
#include <stack>
using namespace std; 
#define INF 1000000000
typedef long long LL; 

class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1; 
        LL newN = (LL)n;
        bool flag = false;
        if(newN < 0) {cout<<"had"<<endl;
        	flag = true; newN = -newN;
        }
        while(newN) {
        	if(newN&1) ret *= x; 
        	x *= x;
        	newN >>= 1;
        }
        if(flag){
        	ret = 1/ret;
        }
        return ret;
    }
};
