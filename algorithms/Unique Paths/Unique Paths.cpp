/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-10 22:17:16
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
public:
    int uniquePaths(int m, int n) {
        int mat[111][111];
        for(int i = 0; i < m; i++) mat[i][0] = 1;
        for(int i = 0; i < n; i++) mat[0][i] = 1;
        for(int i = 1; i < m; i++) {
        	for(int j = 1; j < n; j++) {
        		mat[i][j] = mat[i][j-1] + mat[i-1][j];
        	}
        }
        return mat[m-1][n-1];
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE

	return 0;
}
