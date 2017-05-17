/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-05-16 16:31:27
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
// typedef __int64 LL;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> ret;
        int n = words.size();
        if(n == 0) return ret;
        int m = words[0].size();

        map<string, int> M, M1;
        for(int i = 0; i < n; i++) M[words[i]] ++;
        int length = s.size(), count = 0;

        for(int i = 0; i < m; i++) {
        	count = 0;
        	int right = i - m;
        	for(int j = i; j + m<= length; j += m) {
        		string s1 = s.substr(j, m);
        		if(M.count(s1)) {
        			right = max(right, j - m);
        			while(right + m < length) {
        				string tempS = s.substr(right+m, m);
        				int temp = M[tempS];
        				if(temp > 0 && M1[tempS] < temp) {
        					right += m;
        					M1[tempS] += 1;
        					if(M1[tempS] <= M[tempS]) count ++;
        					if(count >= n) break;
        				}
        				else {
        					break;
        				}
        			}
        			if(count >= n) {
        				ret.push_back(j);
        			}
        			if(M[s1] && M1[s1] == M[s1]) count--;
        			M1[s1] --;
        		}
        		else {
        			M1.clear();
        			right = j;
        			count = 0;
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
	vector<string> v;
	v.push_back("aa");
	v.push_back("aa");
	Solution x= Solution();
	vector<int> ans = x.findSubstring("aaa", v);
	for(int i = 0; i < int(ans.size()); i++){
		printf("%d \n", ans[i]);
	}
	return 0;
}
