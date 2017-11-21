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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size(), length2 = nums2.size(); 
        int length = length1 + length2; 
        if(length & 1) return findSmallestK(nums1, 0, nums2, 0, length/2 + 1);
        else return (findSmallestK(nums1, 0, nums2, 0, length/2) + findSmallestK(nums1, 0, nums2, 0, length/2 + 1)) / 2.0;
    }
    int findSmallestK(vector<int> &nums1, int x1, vector<int> &nums2, int x2, int k) {
        int length1 = nums1.size(), length2 = nums2.size();
        if(length1 - x1 > length2 - x2) return findSmallestK(nums2, x2, nums1, x1, k);
        if(length1 == x1) return nums2[x2+k-1];
        if(k == 1) return min(nums1[x1], nums2[x2]);
        int nx1 = min(x1 + k/2, length1); 
        int nx2 = x2 + k - (nx1 - x1);
        if(nums1[nx1 - 1] > nums2[nx2 - 1]) {
            return findSmallestK(nums1, x1, nums2, nx2, k - (nx2 - x2));
        }
        else if(nums1[nx1 - 1] < nums2[nx2 - 1]) {
            return findSmallestK(nums1, nx1, nums2, x2, k - (nx1 - x1));
        }
        return nums1[nx1 - 1];
    }
};

int main(){
    Solution x = Solution();
    vector<int> n1, n2; 
    n1.push_back(100001); n2.push_back(100000);
    x.findMedianSortedArrays(n1, n2);
}