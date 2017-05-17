/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-10 22:21:02
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
// typedef __int64 LL;

class Solution {
        int mat[111][111];
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if(obstacleGrid.size() == 0) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        mat[0][1] = 1;
        for(int i = 1; i <= m; i++) {
        	for(int j = 1;j <= n; j++) {
        		if(obstacleGrid[i-1][j-1] == 1) continue;
        		mat[i][j] = mat[i-1][j] + mat[i][j-1];
        	}
        }
        return mat[m][n];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

	return 0;
}
