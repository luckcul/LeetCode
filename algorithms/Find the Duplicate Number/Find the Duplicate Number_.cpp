/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-21 14:20:46
 	Problem       : o(n*log(n))
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
    int findDuplicate(vector<int>& nums) {
    	int ret = -1;
    	int l = 1, r = nums.size() - 1;
    	while(l <= r) {
    		int m = (l + r) / 2;
    		int count = 0;
    		for(int i = 0;i < int(nums.size()); i++) {
    			if(nums[i] <= m) count ++;
    		}
    		if(count > m) r = m - 1, ret = m;
    		else l = m + 1;
    	}
    	return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}