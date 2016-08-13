/* ***********************************************
 	Author        : Napoleon
 	Mail          : tyfdream@163.com
 	Created Time  : 2016-08-13 18:31:49
 	Problem       : Integer to Roman
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
//	I 1, V 5, X 10, L 50, C 100, D 500, M 1000
class Solution {
public:
    string intToRoman(int num) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ret = "";
        int id = 0;
        while(num) {
        	if(num < val[id]) {
        		id ++; continue;
        	}
        	ret += symbol[id];
        	num -= val[id];
        }
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	Solution a = Solution();
	cout<<a.intToRoman(3284)<<endl;
	return 0; 
}