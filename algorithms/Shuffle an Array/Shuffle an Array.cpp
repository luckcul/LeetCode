/* ***********************************************
 	Author        : luckcul
 	Mail          : tyfdream@gmail.com
 	Created Time  : 2017-06-27 16:34:53
 	Problem       : Shuffle an Array
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
    vector<int> nums; 
public:
    Solution(vector<int> nums):nums(nums) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums; 
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret=nums; 
        for(int i = 0; i < ret.size(); i++) {
            swap(ret[i], ret[i+ rand()%(ret.size()-i)]);
        }
        return ret; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); 
#endif // ONLINE_JUDGE
	
	
	return 0; 
}