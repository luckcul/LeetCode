/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-21 21:44:45
 	Problem       : Trapping Rain Water
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
    int trap(vector<int>& height) {
        int length = height.size();
        vector<int> a(length, 0);
        vector<int> b(length, 0);
        int last = 0;
        for(int i = 0; i < length; i++) {
        	a[i] = max(height[i], last);
        	last = max(height[i], last);
        }
        last = 0;
        for(int i = length - 1; i >= 0; i--) {
        	b[i] = max(height[i], last);
        	last = max(height[i], last);
        }
        int ret = 0;
        for(int i = 0; i < length; i++) {
        	ret += min(a[i], b[i]) - height[i];
        }
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int x[] = {5,1,2,2,1,0,1,3,2,1,2,1};
	vector<int> v(x, x+3);
	Solution xx =  Solution();
	cout<<xx.trap(v);
	
	return 0; 
}