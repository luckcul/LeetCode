/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-27 10:35:41
 	Problem       : Single Number III
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
    vector<int> singleNumber(vector<int>& nums) {
        int twoXor = 0; 
        for(int i = 0; i < int(nums.size()); i++) {
        	twoXor ^= nums[i];
        }
        int lastBit = (twoXor & (twoXor - 1)) ^ twoXor;
        int retA = 0, retB = 0;
        for(int i = 0; i < int(nums.size()); i++) {
        	if(nums[i] & lastBit) retA ^= nums[i];
        	else retB ^= nums[i];
        }
        vector<int> ret({retA, retB});
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}