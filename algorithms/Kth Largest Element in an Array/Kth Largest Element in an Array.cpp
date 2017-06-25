/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-23 20:32:35
 	Problem       : kth largest element
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
    int findKthLargest(vector<int>& nums, int k) {
    	// convert to find smallest
    	k = nums.size() - k;
    	int l = 0, r = nums.size()-1;
    	while(l <= r) {
    		int t = partition(nums, l, r, k); 
    		if(t == k ) {
    			return nums[t];
    		}
    		if(t > k) {
    			r = t - 1;
    		}
    		else {
    			l = t + 1;
    		}
    	}
    }
    int partition(vector<int>& nums, int l, int r, int k) {
    	int tmp = nums[l];
    	while(l < r) {
    		while(l < r && nums[r] >= tmp) r --; 
    		nums[l] = nums[r];
    		while(l < r && nums[l] <= tmp) l ++;
    		nums[r] = nums[l];
    	}
    	nums[l] = tmp;
    	return l;
    }
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int n[] = {2, 1, 9, 5, 2};
	vector<int> v(n, n + 5);
	Solution x = Solution();
	cout<<x.findKthLargest(v, 3);
	
	return 0; 
}