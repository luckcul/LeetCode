/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-08-09 18:03:18
 	Problem       : Surrounded Regions
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
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	int n, m;
	void dfs(int x, int y, vector<vector<char>>& board){
		if(board[x][y] == '1' || board[x][y] == 'X') return ;
		board[x][y] = '1';
		for(int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			dfs(nx, ny, board);
		}
	}
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n==0) return ;
        m = board[0].size();
        if(m == 0) return ;
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(i > 0 && i < n-1 && j > 0 && j < m-1) continue;
        		if(board[i][j] == 'X') continue;
        		dfs(i, j, board);
        	}
        }

        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(board[i][j] == 'O') board[i][j] = 'X';
        		else if(board[i][j] == '1') board[i][j] = 'O';
        	}
        }
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE


	return 0;
}
