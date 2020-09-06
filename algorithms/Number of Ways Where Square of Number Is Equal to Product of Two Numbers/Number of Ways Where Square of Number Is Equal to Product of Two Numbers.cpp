class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> map1, map2; 
        int len1 = nums1.size(); 
        int len2 = nums2.size(); 
        for(int i = 0; i < len1; i++) {
            for(int j = i+1; j < len1; j++) {
                long long val = 1LL*nums1[i]*nums1[j]; 
                if(map1.find(val) == map1.end()) {
                    map1[val ] = 1; 
                }
                else {
                    map1[val] ++; 
                }
                // cout<<nums1[i]*nums1[j]<<endl;
            }
        }
        
        for(int i = 0; i < len2; i++) {
            for(int j = i+1; j < len2; j++) {
                long long val = 1LL*nums2[i]*nums2[j]; 
                if(map2.find(val) == map2.end()) {
                    map2[val] = 1; 
                }
                else {
                    map2[val] ++; 
                }
                // cout<<nums2[i]*nums2[j]<<endl;
            }
        }
        
        int ret = 0; 
        for(int i = 0; i < len1; i++) {
            long long val = 1LL*nums1[i] * nums1[i]; 
            if(map2.find(val) != map2.end()) {
                ret += map2[val]; 
            }
        }
        for(int i = 0; i < len2; i++) {
            long long val = 1LL*nums2[i] * nums2[i]; 
            if(map1.find(val) != map1.end()) {
                ret += map1[val]; 
            }
        }
        return ret; 
    }
};