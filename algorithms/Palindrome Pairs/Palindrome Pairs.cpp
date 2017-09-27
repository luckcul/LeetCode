/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-11 20:12:25
 	Problem       : Palindrome Pairs
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

class Solution{
	bool isPalindrome(string s) {
		int r = s.size()-1, l = 0;
		while(l < r) {
			if(s[l] != s[r]) return false;
			l ++;
			r --;
		}
		return true;
	}
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	vector<vector<int> > ret;
    	map<string, int> M;
    	for(int i = 0; i < int(words.size()); i++) {
    		M[words[i]] = i;
    	}
    	if(M.find("") != M.end()){
    		int emptyIndex = M[""];
    		for(int i = 0; i < int(words.size()); i++) {
    			if(i != emptyIndex && isPalindrome(words[i])){
    				vector<int> tmp; 
    				tmp.push_back(emptyIndex); tmp.push_back(i);
    				ret.push_back(tmp);
    			}
    		}
    	}
    	for(int i = 0; i < int(words.size()); i++) {
    		for(int j = 0; j < int(words[i].size()); j++) {
    			string left = words[i].substr(0, j);
    			string right = words[i].substr(j,words[i].size()-j);
    			string leftR(left);
    			reverse(leftR.begin(), leftR.end());
    			string rightR(right);
    			reverse(rightR.begin(), rightR.end());
    			if(isPalindrome(left) && M.find(rightR) != M.end() && M[rightR] != i){
    				vector<int> tmp; 
    				tmp.push_back(M[rightR]); tmp.push_back(i);
    				ret.push_back(tmp);
    			}
    			if(isPalindrome(right) && M.find(leftR) != M.end() && M[leftR] != i) {
    				vector<int> tmp;
    				tmp.push_back(i); tmp.push_back(M[leftR]);
    				ret.push_back(tmp);
    			}
    		}
    	}
    	return ret;
    }
};

// O(n^3)
/*class Solution {
	bool check(string a, string b) {
		int lengthA = a.size();
		int lengthB = b.size();
		int i = 0, j = lengthB-1, leftAt=0, rightAt=1;
		if(lengthA == 0) leftAt=1;
		if(lengthB == 0) j = lengthA-1, rightAt=0;
		while(leftAt == 0 && rightAt == 1 || (leftAt == rightAt && i <= j)) {
			char chLeft, chRight;
			chLeft = leftAt? b[i]:a[i];
			chRight = rightAt? b[j]:a[j];
			if(chLeft != chRight) return false;
			i++;
			j--;
			if(leftAt == 0 && i >= lengthA) {
				leftAt = 1; i = 0;
			}
			if(rightAt == 1 && j < 0) {
				rightAt = 0; j = lengthA-1;
			}
		}
		return true;
	}
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
    	vector<vector<int> > ret;
        int length = words.size();
        for(int i = 0; i < length; i++) {
        	for(int j = i+1; j < length; j ++) {
        		if(check(words[i], words[j])){
        			vector<int> tmp;
        			tmp.push_back(i); tmp.push_back(j);
        			ret.push_back(tmp);
        		}
        		if(check(words[j], words[i])){
        			vector<int> tmp;
        			tmp.push_back(j); tmp.push_back(i);
        			ret.push_back(tmp);
        		}
        	}
        }
        return ret;
    }
};
*/
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	string str[] = {"abcd", "dcba", "lls", "s", "ssll", ""};
	vector<string> words(str, str+6);
	Solution x = Solution();
	vector<vector<int> > ret = x.palindromePairs(words);
	for(int i = 0; i < ret.size(); i++) {
		cout<<ret[i][0]<<" "<<ret[i][1]<<endl;
	}
	
	return 0; 
}