/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-20 15:53:55
 	Problem       : leetcode
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
    int maxRotateFunction(vector<int>& A) {
        int length = A.size();
        int sum = 0, temp = 0;
        for(int i = 0; i < length; i++) sum += A[i], temp += i * A[i];
        int ret = temp;
        for(int i = length - 1; i > 0; i--) {
        	temp += sum - length * A[i];
        	ret = max(ret, temp);
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