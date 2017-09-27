/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-26 14:23:33
 	Problem       : Top K Frequent Elements
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> ret; 
     	unordered_map<int, int> M;
     	for(int i = 0; i < int(nums.size()); i++) {
     		M[nums[i]] += 1;
     	}
     	vector<vector<int>> bucket(nums.size() + 1);
     	for(auto it : M) bucket[it.second].push_back(it.first);
     	for(int i = nums.size(); i >= 0; i --) {
     		for(int j = 0; j < bucket[i].size(); j ++ ) {
     			ret.push_back(bucket[i][j]); 
     			if(ret.size() >= k) return ret;
     		}
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