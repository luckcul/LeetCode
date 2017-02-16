/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-01-19 16:19:46
 	Problem       : sudoku solver
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
	int m[11][11];
	int out[11][11];
	int vis[11][11][11];// change it !
	bool flag;
	void setVis(int x, int y, int val, int flag) {
		if(val < 0) return;
		for(int k = 0; k < 9; k++) {
			vis[x][k][val] += flag;
			vis[k][y][val] += flag;
		}
		vis[x][y][val] -= flag;
		int sx = (x/3)*3;
		int sy = (y/3)*3;
		for(int ax = 0; ax < 3; ax ++) {
			for(int ay = 0; ay < 3; ay ++) {
				int nx = sx+ax;
				int ny = sy+ay;
				if(nx == x || ny == y) continue;
				vis[nx][ny][val] += flag;
			}
		}
	}
	bool nextxy(int &x, int &y) {
		if(x >= 8 && y >= 8) return false;
		if(y < 8) y++;
		else{
			y = 0; x++;
		}
		return true;
	}
	void dfs(int x, int y ) {
		if(flag) return ;
		if(m[x][y] > 0) {
			out[x][y] = m[x][y];
			bool f = nextxy(x, y);
			if(!f) {
				flag = true;
				return ;
			}
			else {
				dfs(x, y);
			}
		}
		else {
			int xx, yy; 
			xx = x, yy = y;
			for(int i = 1; i <= 9; i++) {
				if(flag) return ;
				x = xx, y = yy;
				if(vis[x][y][i]) continue;
				out[x][y] = i;
				setVis(x, y, i, 1);
				bool f = nextxy(x, y);
				if(!f) {
					flag = true;
					setVis(xx, yy, i, -1);
					return ;
				}
				else {
					dfs(x, y);
					setVis(xx, yy, i, -1);
				}
			}
		}
	}
public:
    void solveSudoku(vector<vector<char> >& board) {
    	memset(vis, 0, sizeof(vis));
        for(int i = 0; i < 9; i++) {
        	for(int j = 0; j < 9; j++) {
        		m[i][j] = (board[i][j] == '.' ? -1 : board[i][j] - '0');
        		int temp = m[i][j];
        		setVis(i, j, temp, 1);        		
        	}
        }
        flag = false;
        dfs(0, 0);
        for(int i = 0; i < 9; i++) {
        	for(int j = 0; j < 9; j++) {
        		board[i][j] = '0' + out[i][j];
        	}
        }

    }
};