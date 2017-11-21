/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-25 22:08:47
 	Problem       : Add Binary
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
    string addBinary(string a, string b) {
        string c = "";
        int i = a.size() - 1, j = b.size() - 1, last = 0;
        while(i >= 0 || j >= 0) {
        	int a_ = 0, b_ = 0;
        	if(i >= 0) a_ = a[i] == '0'?0:1;
        	if(j >= 0) b_ = b[j] == '0'?0:1;
        	int c_ = a_+b_+last;
        	if(c_&1) c = "1"+c;
        	else c = "0" + c;
        	last = (c_>>1)? 1:0;
        	i --; j --;
        }
        if(last) c = "1" + c;
        return c;
    }
};

int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	string in; 
	cin>>in;
	Solution x = Solution();
	cout<<x.addBinary(in, "111");
	
	return 0; 
}