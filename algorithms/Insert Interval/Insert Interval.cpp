/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-07-22 14:39:05
 	Problem       : Insert Interval
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


// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> ret;
        int length = intervals.size();
        if(length == 0) {
        	ret.push_back(newInterval); return ret;
        } 
        int startIndex = length, endIndex = -1;
        for(int i = 0; i < length; i++) {
        	if(intervals[i].end >= newInterval.start && startIndex == length){
        		startIndex = i;
        	}
        	if(intervals[i].start <= newInterval.end) {
        		endIndex = i;
        	}
        }
        if(startIndex == length) {
        	intervals.push_back(newInterval);
        	return intervals;
        }
        else if(endIndex  == -1) {
        	ret.push_back(newInterval);
        	for(int i = 0; i < length; i++) ret.push_back(intervals[i]);
        	return ret;
        }
        else {
        	for(int i = 0; i < startIndex; i++) {
        		ret.push_back(intervals[i]);
        	}
        	ret.push_back(Interval(min(newInterval.start, intervals[startIndex].start), max(newInterval.end, intervals[endIndex].end)));
        	for(int i = endIndex + 1; i < length; i++) {
        		ret.push_back(intervals[i]);
        	}
        	return ret;
        }

    }
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	vector<Interval> v;
	v.push_back(Interval(1, 5));
	Solution x = Solution();
	vector<Interval> ans = x.insert(v, Interval(0, 0));
	for(int i = 0; i < ans.size(); i++) {
		cout<<ans[i].start<<" "<<ans[i].end<<endl;
	}
	
	return 0; 
}