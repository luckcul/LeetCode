/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-04-14 16:41:28
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
//typedef __int64 LL;
class Solution {
public:
	int newIndex(int index, int len) {
		int half = len / 2;
		if(index < half) {
			return 1 + (index) * 2;
		}
		else {
			return (index - half)*2;
		}
	}
    void wiggleSort(vector<int>& nums) {
		int len = nums.size();
		vector<int>::iterator mid = nums.begin() + len / 2;
		nth_element(nums.begin(), mid, nums.end());
		int midVal = *mid;
		// for(int i = 0; i < 11; i++) cout<< newIndex(i, 11)<<" ";
		int low = 0, cur = 0, high = len-1;
		while(cur <= high) {
			int newLow = newIndex(low, len);
			int newCur = newIndex(cur, len);
			int newHigh = newIndex(high , len);
			if(nums[newCur] == midVal) {
				cur ++;
			}
			else if(nums[newCur] > midVal) {
				swap(nums[newLow], nums[newCur]);
				cur ++; low++;
			}
			else{
				swap(nums[newCur], nums[newHigh]);
				high --;
			}
		}
    }
};


int main() {
	 Solution x = Solution();
    vector<int> p;
    // p.push_back(1);
    p.push_back(1);
    p.push_back(2);
    p.push_back(6);
    p.push_back(3);
    p.push_back(2);
    p.push_back(2);
    x.wiggleSort(p);

    for(int i = 0; i < int(p.size()); i++) {
        cout<<p[i]<<" ";
    }
	return 0;
}
