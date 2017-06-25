/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-20 15:05:43
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
//typedef __int64 LL; 

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int n = matrix.size();
        if(n == 0) return ret;
        int m = matrix[0].size();
        int upper = n + m - 2;
        for(int i = 0; i <= upper; i++) {
        	int maxX = min(n-1, i);
        	int maxY = min(m-1, i);
        	int minX = i - maxY;
        	if(i & 1) {
        		for(int x = minX; x <= maxX; x ++) {
        			ret.push_back(matrix[x][i - x]);
        		}
        	}
        	else {
        		for(int x = maxX; x >= minX; x --) {
        			ret.push_back(matrix[x][i - x]);
        		}
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