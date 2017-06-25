/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-20 16:16:15
 	Problem       : UTF-8 Validation
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
    bool validUtf8(vector<int>& data) {
        int length = data.size();
        int lastOnes = 0;
        for(int i = 0; i < length; i++) {
        	int num = data[i];
        	int ones = 0;
        	for(int j = 7; j >= 0; j --) {
        		if((num>>j)&1) ones ++;
        		else break;
        	}
        	if(ones > 4) return false;
        	if(ones == 0 && lastOnes) return false;
        	if(ones == 0) continue;
        	if(ones == 1){
        		if(lastOnes) lastOnes --;
        		else return false;
        	}
        	else {
        		if(lastOnes) return false;
        		else lastOnes = ones - 1;
        	}
        }
        if(lastOnes) return false;
        return true;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	vector<int> v; 
	v.push_back(193); v.push_back(130); v.push_back(1); 
	Solution x = Solution();
	cout<<x.validUtf8(v);
	
	return 0; 
}