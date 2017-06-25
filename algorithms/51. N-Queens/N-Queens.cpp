/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-22 13:08:45
 	Problem       : N-Queens using bit
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
    void dfs(int now, int rowStatue, int leftStatue, int rightStatue, int n) {
    	if(now >= n) {
    		save(n);
    		return ;
    	}
    	int pos = ((1<<n)-1) & (~(rowStatue | leftStatue | rightStatue));
    	while(pos) {
    		int nowRow = pos & (-pos);
    		int len = 0, tempRow = nowRow;
    		while(tempRow) len++, tempRow>>=1;
    		vis.push_back(len - 1);
    		dfs(now+1, rowStatue|nowRow, (leftStatue | nowRow)<<1, (rightStatue | nowRow)>>1, n);
    		vis.pop_back();
    		pos = pos - nowRow;
    	}
    }
public:
    vector<vector<string> > solveNQueens(int n) {
    	ret.clear();
        dfs(0, 0, 0, 0, n);
       return ret;
   }
};


int main() {
	Solution x = Solution();
	vector<vector<string> > ret = x.solveNQueens(4);
	for(int i = 0; i < int(ret.size()); i++) {
		for(int j = 0; j < int(ret[i].size()); j++) {
			cout<<ret[i][j]<<endl;
		}
		cout<<endl;
	}
	
	return 0; 
}