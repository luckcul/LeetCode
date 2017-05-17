/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-08 20:53:18
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
    vector<vector<int>> subsets(vector<int>& nums) {
    	vector<vector<int>> ret;
        int len = nums.size();
        for(int i = 0; i < (1<<len); i++) {
        	vector<int> temp;
        	for(int j = 0; j < len; j++) {
        		if(i & (1<<j)) temp.push_back(nums[j]);
        	}
        	ret.push_back(temp);
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
