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
//typedef __int64 LL; 
const int INF = 1000000000;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans, absAns = INF;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size; i++) {
        	int low = i+1, high = size -1; 
        	while(low < high) {
        		if(abs(nums[i] + nums[low] + nums[high] - target) < absAns) {
        			ans = nums[i] + nums[low] + nums[high];
        			absAns = abs(ans - target);
        		}
        		if(nums[i] + nums[low] + nums[high] == target) return target;
        		else if(nums[i] + nums[low] + nums[high] > target) high--;
        		else low++;
        	}
        }
        return ans;
    }
};