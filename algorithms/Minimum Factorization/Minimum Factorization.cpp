/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-02 15:55:15
 	Problem       : Minimum Factorization
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
    int smallestFactorization(int a) {
    	if(a == 1) return a;
        int factors[] = {2, 3, 5, 7};
        int counts[] = {0, 0, 0, 0};
        for(int i = 0; i < 4; i++) {
        	while(a % factors[i] == 0) {
        		counts[i] ++;
        		a /= factors[i];
        		// cout<<factors[i]<<endl;
        	}
        }
        if(a != 1) return 0;
        multiset<int> S;
        for(int i = 2; i < 4; i++) {
        	for(int j = 0; j < counts[i]; j++) {
        		S.insert(factors[i]);
        	}
        }
        while(counts[1] >= 2) {
        	S.insert(9);
        	counts[1] -= 2;
        }
        
        while(counts[0] >= 3) {
        	S.insert(8);
        	counts[0] -= 3;
        }
        while(counts[1] >= 1 && counts[0] >= 1) {
        	S.insert(6);
        	counts[0] --; counts[1] --;
        }
        if(counts[1] >= 1) S.insert(3);
        if(counts[0] >= 2) S.insert(4);
        else if(counts[0] >= 1) S.insert(2);
        multiset<int>::iterator it;
        int ret = 0;
        for(it = S.begin(); it != S.end(); it ++) { 
        	if(ret > ((1<<31)-1)/10) return 0;
        	ret *= 10;
        	if(ret > ((1<<31)-1) - (*it)) return 0;
        	ret += (*it);
        }
        return ret;
    }
};

int main() {
	Solution x = Solution();
	cout<<x.smallestFactorization(4);	
	
	return 0; 
}