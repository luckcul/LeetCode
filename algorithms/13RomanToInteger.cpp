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

//	I 1, V 5, X 10, L 50, C 100, D 500, M 1000
class Solution {
public:
    int romanToInt(string s) { // s is not empty
    	map<char, int> M;
    	M['I'] = 1; M['V'] = 5; M['X'] = 10; M['L'] = 50; 
    	M['C'] = 100; M['D'] = 500; M['M'] = 1000;
    	int ret = M[s[0]];
        for(int i = 1; i < s.length(); i ++) {
        	int a = M[s[i-1]], b = M[s[i]];
        	if(b <= a) ret += b;
        	else ret += b, ret -= 2*a;
        }
        return ret; 
    }
};
