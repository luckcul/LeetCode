/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-25 21:12:10
 	Problem       : Gas Station
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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < int(gas.size()); i++) {
        	gas[i] -= cost[i];
        }
        int last = 0, Min = INF, index;
        for(int i = 0; i < int(gas.size()); i++) {
        	last += gas[i];
        	if(last < Min) {
        		Min = last; index = i;
        	}
        }
        if(last < 0) return -1;
        return ((index + 1) % gas.size());
    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}