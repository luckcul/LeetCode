/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-19 13:15:20
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
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int l = 0, r = length - 1;
        while(l <= r){
        	int m = (l+r)>>1;
        	if(nums[m] == target) return m;
        	if(nums[m] < nums[r]){
        		if(target >= nums[m] && target <= nums[r]) l = m + 1;
        		else r = m - 1;
        	}
        	else {
        		if(target <= nums[m] && target >= nums[l]) r = m - 1;
        		else l = m + 1;
        	}
        }
        return -1;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	cout<<"xx"<<endl;
	
	return 0; 
}