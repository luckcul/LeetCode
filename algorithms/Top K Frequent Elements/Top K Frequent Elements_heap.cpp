/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-26 14:11:07
 	Problem       : Top K Frequent Elements
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     	unordered_map<int , int> M;
     	priority_queue<pair<int, int>> Q;
     	for(int i = 0; i < nums.size(); i++) {
     		M[nums[i]] += 1;
     	}   
     	// for(priority_queue<pair<int, int>>::iterator it = M.begin(); it != M.end(); it ++ ) {
     	// 	Q.push(make_pair(it->end, it->first));
     	// }
     	for(auto x : M) Q.push(make_pair(x.second, x.first));
     	vector<int> ret; 
     	for(int i = 0; i < k && (!Q.empty()); i++) {
     		pair<int, int> temp = Q.top();
     		ret.push_back(temp.second);
     		Q.pop();
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