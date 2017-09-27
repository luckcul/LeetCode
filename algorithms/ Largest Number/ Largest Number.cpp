/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-08-09 15:41:34
 	Problem       :  Largest Number
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 


class Solution {
	static bool cmp(string& a, const string& b){
	    return a +b > b + a;
	}
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numss;
        for(int i = 0; i < int(nums.size()); i++) {
        	numss.push_back(to_string(nums[i]));
        }
        sort(numss.begin(), numss.end(), cmp);
        string ret = "";
        for(int i = 0; i < int(numss.size());i++){
        	ret += numss[i];
        }
        if(ret[0] == '0' || ret.size() == 0) ret = "0";
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	int nums[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> x(nums, nums+22);
	Solution s = Solution();
	cout<<s.largestNumber(x);
	
	return 0; 
}