/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-19 13:24:17
 	Problem       : Brick Wall
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> M;
        for(int i = 0; i < int(wall.size()); i++) {
        	int tempSum = 0;
        	for(int j = 0; j < int(wall[i].size()) - 1; j++) {
        		tempSum += wall[i][j];
        		M[tempSum] += 1;
        	}
        }
        int totalCol = wall.size();
        int ret = totalCol;
        for(unordered_map<int, int>::iterator it = M.begin(); it != M.end(); it ++) {
        	int key = it->first;
        	int value = it->second;
        	ret = min(ret, totalCol - value);
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