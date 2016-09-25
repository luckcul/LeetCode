/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@163.com
 	Created Time  : 2016-07-30 15:58:06
 	Problem       : reverString
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

class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }
};