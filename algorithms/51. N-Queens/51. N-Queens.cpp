/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-21 10:18:03
 	Problem       : 51. N-Queens
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
	vector<int> vis;
    vector<vector<string> > ret;
    void save(int n){
    	vector<string> origin(n, string(n, '.'));
    	for(int i = 0; i < n; i++) {
    		origin[i][vis[i]] = 'Q';
    	}
    	ret.push_back(origin);
    }
    bool check(int x, int y){
    	for(int i = 0; i < int(vis.size()); i++) {
    		if(vis[i] == y) return false;
    		if(abs(x - i) == abs(y - vis[i])) return false;
    	}
    	return true;
    }
    void dfs(int now, int n) {
    	if(now >= n) {
    		save(n);
    		return;
    	}
    	for(int i = 0; i < n; i++) {
    		bool flag = check(now, i);
    		if(flag) {
    			vis.push_back(i);
    			dfs(now+1, n);
    			vis.pop_back();
    		}
    	}
    }
public:
    vector<vector<string> > solveNQueens(int n) {
    	ret.clear();
        dfs(0, n);
       return ret;
   }
};


int main() {
	Solution x = Solution();
	vector<vector<string> > ret = x.solveNQueens(5);
	for(int i = 0; i < int(ret.size()); i++) {
		for(int j = 0; j < int(ret[i].size()); j++) {
			cout<<ret[i][j]<<endl;
		}
		cout<<endl;
	}
	
	return 0; 
}