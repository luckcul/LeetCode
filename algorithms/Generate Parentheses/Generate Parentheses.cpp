/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-27 20:53:06
 	Problem       : Generate Parentheses
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
	vector<string> ret;
	void dfs(string s, int sum, int left, int depth, int n){
		if(depth >= n * 2) {
			ret.push_back(s);
			return ;
		}
		if(left < n){
			dfs(s+"(", sum + 1, left + 1, depth + 1, n);
		}
		if(sum > 0) {
			dfs(s+")", sum - 1, left, depth + 1, n);
		}
	}
public:
    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, 0, n);
        return ret;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	Solution x = Solution();
	vector<string> v = x.generateParenthesis(5);
	for(int i = 0; i < int(v.size()); i++) {
		cout<<v[i]<<endl;
	}
	
	return 0; 
}