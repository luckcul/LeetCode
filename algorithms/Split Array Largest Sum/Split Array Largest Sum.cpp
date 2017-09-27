/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-29 21:17:59
 	Problem       : Split Array Largest Sum -- binary search...
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
typedef long long LL; 

class Solution {
	bool check(vector<int> nums, int m, LL s) {
		LL lastS = 0;
		int times = 0;
		for(int i = 0; i < int(nums.size()); i++) {
			if(times >= m) return false;
			if(lastS + nums[i] > s) {
				times += 1;
				lastS = 0; 
				i --;
			}
			else {
				lastS += nums[i];
			}
		}
		return true;
	}
public:
    int splitArray(vector<int>& nums, int m) {
        LL l = 0;
        LL r = 0;
        for(int num:nums) r += num;
        LL ret = -1;
        while(l <= r) {
        	LL mid = (l+r)>>1;
        	bool flag = check(nums, m, mid);
        	if(flag) {
        		ret = mid;
        		r = mid - 1;
        	}
        	else l = mid + 1;
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