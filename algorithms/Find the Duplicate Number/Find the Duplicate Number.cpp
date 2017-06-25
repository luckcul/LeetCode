/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-20 22:24:08
 	Problem       : problem
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
    	if(nums.size() <= 1) return -1;
    	int slow = nums[0];
    	int fast = nums[nums[0]];
    	while(slow != fast) {
    		slow = nums[slow];
    		fast = nums[nums[fast]];
    	}
    	slow = 0;
    	while(slow != fast) {
    		slow = nums[slow];
    		fast = nums[fast];
    	}
    	return slow;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int x[] = {1, 4, 2, 2, 3};
	vector<int> nums(x, x+5);
	Solution xx = Solution();
	cout<<xx.findDuplicate(nums);
	
	return 0; 
}