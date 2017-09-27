/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-28 09:20:59
 	Problem       : Gray Code
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
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for(int i = 0; i < n; i++) {
        	int size = ret.size();
        	for(int j = size-1; j >= 0; j--) {
        		ret.push_back((1<<(i)) | ret[j]);
        	}
        }
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	Solution x = Solution();
	vector<int> v = x.grayCode(3);
	for(int i = 0; i < v.size(); i++) cout<<v[i]<<" ";
	
	return 0; 
}