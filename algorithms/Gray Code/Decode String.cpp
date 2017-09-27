/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-28 09:41:30
 	Problem       : Decode String
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
	bool isDigital(char ch) {
		return (ch >= '0' && ch <= '9');
	}
	string dfs(string s) {
		string ret = "";
		int size = s.size();
		for(int i = 0; i < size; i++) {
			if(isDigital(s[i])) {
				int times = 0;
				while(isDigital(s[i])){
					times *= 10; times += s[i] - '0';
					i++;
				}
				int start = i+1;
				int count = 1;
				while(count >= 1) {
					i++;
					if(s[i] == '[') count ++; 
					else if(s[i] == ']') count --;
				}
				string tmp = dfs(s.substr(start, i-start));
				for(int j = 0; j < times; j ++) ret += tmp;
			}
			else{
				string tmp = "";
				while(!isDigital(s[i]) && i < size){
					tmp += s[i];
					i++;
				}
				i--;
				ret += tmp;
			}
		}
		return ret;
	}
public:
    string decodeString(string s) {
        string ret = dfs(s);
        return ret;
    }
};

int main() {
	Solution x = Solution();
	cout<<x.decodeString("100[le]");
	
	return 0; 
}