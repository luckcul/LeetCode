/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-18 13:23:02
 	Problem       : leetcode
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
	int findIndex(vector<int> nums, int target, int l, int r) {
		while(l <= r) {
			int m = (l + r)/2;
			if(nums[m] == target) return m;
			else if(nums[m] > target) {
				r = m-1;
			}
			else l = m+1;
		}
		return -1;
	}
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int l = 0, r = length - 1;
        int index = -1;
        while(l <= r) {
        	int m = (l + r) / 2;
        	if(nums[m] >= nums[0]){
        		l = m + 1;
        	}
        	else {
        		index = m;
        		r = m - 1;
        	}
        }
        if(index == -1) index = length;
        int index1 = findIndex(nums, target, 0, index-1);
        int index2 = findIndex(nums, target, index, length - 1);
        return max(index1, index2);
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(1);
	// nums.push_back(4);
	Solution x = Solution();
	cout<<x.search(nums, 1)<<endl;
	return 0; 
}