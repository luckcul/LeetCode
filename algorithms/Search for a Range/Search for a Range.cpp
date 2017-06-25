/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-20 16:33:47
 	Problem       : Search for a Range
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
	int binarySearch(vector<int> nums, int target, bool mode){
		int l = 0, r = nums.size()-1;
		int ret = -1;
		while(l <= r){
		printf("LR: %d %d \n", l, r);
			int m = (l+r)>>1;
			int num = nums[m];
			if(mode) {
				if(num < target) l = m + 1;
				else r = m - 1;
				if(num == target) ret = m;
			}
			else {
				if(num <= target) l = m + 1;
				else r = m - 1;
				if(num == target) ret = m;
			}
		}
		return ret;
	}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = binarySearch(nums, target, true);
        int r = binarySearch(nums, target, false);
        vector<int> ret;
        ret.push_back(l), ret.push_back(r);
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int x[] = {1, 1};
	std::vector<int> v(x, x+2);
	Solution t = Solution();
	std::vector<int> vv = t.searchRange(v, 1);
	cout<<vv[0]<<" "<<vv[1]<<endl;
	
	return 0; 
}