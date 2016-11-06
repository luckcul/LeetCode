/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2016-11-05 14:03:20
 	Problem       : reverse words in string
************************************************ */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
#include <set>
using namespace std; 
#define INF 1000000000
//typedef __int64 LL; 
class Solution {
public:
    void reverseWords(string &s) {
        string ret = "";
        stringstream ss;
        ss<<s;
        string t;
        while(ss>>t){
        	reverse(t.begin(), t.end());
        	if(ret != "") ret += " ";
        	ret += t;
        }
        s = ret;
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
};
int main() {
	Solution x = Solution();
	string s = " as bb lll ";
	x.reverseWords(s);
	
	return 0; 
}