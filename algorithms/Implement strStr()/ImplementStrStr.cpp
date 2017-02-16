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
    int strStr(string haystack, string needle) {
    	if(haystack == needle) return 0 ;
        int len1 = haystack.size();
        int len2 = needle.size();
        for(int i = 0; i <= len1 - len2; i++) {
        	int tempI = i;
        	int j = 0;
        	while(haystack[tempI] == needle[j] && tempI < len1 && j < len2) {
        		tempI ++;
        		j ++;
        	}
        	if(j >= len2) {
        		return i;
        	}
        }
        return -1;
    }
};