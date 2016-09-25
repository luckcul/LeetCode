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
    vector<int> countBits(int num) {
        vector<int> v(num+1, 0);
        v[1] = 1;
        for(int i = 2; i <= num; i++) {
        	v[i] = v[i & (i-1)] + 1;
        }
        return v;
    }
};