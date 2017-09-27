/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-08-10 18:26:45
 	Problem       : String to Integer (atoi) 
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
    int myAtoi(string str) {
        int ret = 0;
        int INF_MAX = (1<<31)-1, INF_MIN = (1<<31);
        int s = 0;
        bool neg = false;
        while(str[s] == ' ') s += 1;
        if(str[s] == '-') neg = true, s += 1;
        else if (str[s] == '+') s += 1;
        for(;s < str.size() && str[s] >= '0' && str[s] <= '9'; s++){
        	if(ret > INF_MAX / 10 || (ret == INF_MAX / 10 && str[s] > '7')){
        		return neg ? INF_MIN: INF_MAX;
        	}
        	ret *= 10;
        	ret += str[s] - '0';
        }
        return neg ? -ret: ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}